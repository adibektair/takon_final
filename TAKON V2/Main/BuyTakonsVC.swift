//
//  BuyTakonsVC.swift
//  TAKON V2
//
//  Created by root user on 10/8/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class BuyTakonsVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    var service: Service?
    var partner: Partner?
    let fields : [PaymentFields] = [.name, .amount, .phoneNumber, .phone, .button]
    
    
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
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.setTitle("Оплатить", for: .normal)
            cell.button.addTarget(self, action: #selector(self.pay(_:)), for: .touchUpInside)
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch fields[indexPath.row] {
        case .amount:
            return 80.0
        case .phone:
            return 160.0
        default:
            return 35
        }
    }
    @objc func back(_ sender: UIButton){
        self.navigationController?.popViewController(animated: true)
    }
    @objc func pay(_ sender: UIButton){
        let amountCell = self.tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! OnlinePaymentCell
        let amount = amountCell.amountTextField.text!
        let price = Int(amount)! * (self.service?.paymentPrice!)!
        CardsVC.open(vc: self, service: self.service!, partner: self.partner!, isPayment: true, price: price)
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
