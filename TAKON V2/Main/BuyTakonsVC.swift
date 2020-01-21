//
//  BuyTakonsVC.swift
//  TAKON V2
//
//  Created by root user on 10/8/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
import ObjectMapper

class BuyTakonsVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    var service: Service?
    var partner: Partner?
    let fields : [PaymentFields] = [.name, .amount, .phoneNumber, .phone, .button, .walletPay]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Пополнить таконы"
        self.tableView.delegate = self
        self.tableView.dataSource = self
        tableView.backgroundColor = .clear
        tableView.allowsSelection = false
        tableView.separatorStyle = .none
        view.backgroundColor = #colorLiteral(red: 0.8941176471, green: 0.9176470588, blue: 0.9490196078, alpha: 1)
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
        self.tableView.register(UINib(nibName: "PaymentTVC", bundle: nil), forCellReuseIdentifier: "PaymentTVC")
        self.tableView.register(UINib(nibName: "OnlinePaymentCell", bundle: nil), forCellReuseIdentifier: "OnlinePaymentCell")
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        
        
    }

    @IBOutlet var tableView: UITableView!
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return fields.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        switch fields[indexPath.row] {
        case .name:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.backgroundColor = .clear
            cell.innerTextLabel.text = "Название услуги и количество"
            return cell
        case .amount:
            let cell = tableView.dequeueReusableCell(withIdentifier: "PaymentTVC", for: indexPath) as! PaymentTVC
            if let url = partner?.imagePath{
                let img = URL(string: imageUrl + url.encodeUrl)
                cell.logoImageView.sd_setImage(with: img, completed: nil)
            }
            cell.changeButton.addTarget(self, action: #selector(self.back(_:)), for: .touchUpInside)
            cell.serviceNameLabel.text = self.service?.name!
            cell.takonAmountLabel.text = "1 такон = \(service!.paymentPrice!) тг."
            cell.amountTextField.removeFromSuperview()
            cell.textView.removeFromSuperview()
            return cell
        case .phoneNumber:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.backgroundColor = .clear
            cell.innerTextLabel.text = "Сколько таконов вы хотите приобрести?"
            
            return cell
        case .phone:
            let cell = tableView.dequeueReusableCell(withIdentifier: "OnlinePaymentCell", for: indexPath) as! OnlinePaymentCell
            cell.price = self.service!.paymentPrice!
            cell.amountTextField.keyboardType = .numberPad
            return cell
            
        case .button:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
                  cell.button.setTitle("Оплатить", for: .normal)
                  cell.button.addTarget(self, action: #selector(self.pay(_:)), for: .touchUpInside)
                  return cell
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.setTitle("Оплатить WalletOne", for: .normal)
            cell.button.backgroundColor = .white
            cell.button.cornerRadius(radius: 8, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
            cell.button.setTitleColor(#colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1), for: .normal)
            cell.button.addTarget(self, action: #selector(self.walletOne(_:)), for: .touchUpInside)
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch fields[indexPath.row] {
        case .amount:
            return 80.0
        case .phone:
            return 160.0
        case .name:
            return 35.0
        case .phoneNumber:
            return 35.0
        default:
            return 90
        }
    }
    @objc func back(_ sender: UIButton){
        self.navigationController?.popViewController(animated: true)
    }
    @objc func pay(_ sender: UIButton){
        let amountCell = self.tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! OnlinePaymentCell
        if let amount = amountCell.amountTextField.text{
            let price = Int(amount)! * (self.service?.paymentPrice!)!
            CardsVC.open(vc: self, service: self.service!, partner: self.partner!, isPayment: true, price: price)
        }else{
            self.showAlert(title: "Внимание", message: "Введите количество")
        }
        
    }
    @objc func walletOne(_ sender: UIButton){
        let amountCell = self.tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! OnlinePaymentCell
        if let amount = amountCell.amountTextField.text{
           
            let json = ["service_id" : self.service!.id!, "amount" : amount] as [String: AnyObject]
            self.startLoading()
            self.payByWalletOne(params: json, completionHandler: { resp in
                
                WalletOneVC.open(vc: self, url: resp)
            })
            
        }else{
            self.showAlert(title: "Внимание", message: "Введите количество")
        }
        
    }
    
    static func open(vc: UIViewController, service : Service, partner: Partner){
        let viewController = BuyTakonsVC(nibName: "BuyTakonsVC", bundle: nil)
        viewController.service = service
        viewController.partner = partner
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
}
extension BuyTakonsVC{
    func payByWalletOne (params: [String: AnyObject], completionHandler: @escaping (_ str: String) -> ()){
           
           let headers = [
               "Content-Type": "application/x-www-form-urlencoded",
               "Authorization" : "Bearer " + getToken()
           ]
           
           Alamofire.request(url + "create-wallet-order", method: .post, parameters: params, headers: headers).responseJSON { response in
                        if let code = response.response?.statusCode{
                            self.stopLoading()
                            if code == 200{
                                if let result = response.result.value{
                                    let JSON = result as! Dictionary<String, Any>
                                    
                                    completionHandler(JSON["url"] as! String)
                                }
                            }else{
                                self.showAlert(title: "Some error occured", message: "Try again later")
                            }
                        }
                        print(response)
                }
       }
}
