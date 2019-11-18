//
//  CardsVC.swift
//  TAKON V2
//
//  Created by root user on 10/9/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire

class CardsVC: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    var cards = [Card1]()
    var service: Service?
    var partner: Partner?
    var selectedId = 0
    var isPayment = false
    var price = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.tableFooterView = UIView()
        self.tableView.allowsSelection = false
        self.tableView.delegate = self
        if !isPayment{
            self.title = "Методы оплаты"
        }else{
            self.title = "Оплатить"

        }
        self.tableView.dataSource = self
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        self.tableView.register(UINib(nibName: "CardCell", bundle: nil), forCellReuseIdentifier: "CardCell")
        self.tableView.register(UINib(nibName: "AddCardCell", bundle: nil), forCellReuseIdentifier: "AddCardCell")
        self.startLoading()
        self.getMyCards(completionHandler: { cards in
            self.stopLoading()
            self.cards = cards
            self.tableView.reloadData()
        })
    }

    @IBOutlet var tableView: UITableView!
    
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch indexPath.row {
        case 0:
            return 35
        case 3 + cards.count - 2:
            return 70
        case 3 + cards.count - 1:
            return 120
            
        default:
            return 70
        }
    }
    
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        switch indexPath.row {
        case 0:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.backgroundColor = .clear
            if self.isPayment{
                cell.innerTextLabel.text = "Выберите способ оплаты"
            }else{
                cell.innerTextLabel.text = "Ваши карты"
            }
            
            return cell
        case 3 + cards.count - 2:
            let cell = tableView.dequeueReusableCell(withIdentifier: "AddCardCell", for: indexPath) as! AddCardCell
            cell.addCardButton.addTarget(self, action: #selector(self.addCardVC(_:)), for: .touchUpInside)
            
            return cell
        case 3 + cards.count - 1:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.addTarget(self, action: #selector(self.pay(_:)), for: .touchUpInside)
            cell.button.setTitle("Оплатить", for: .normal)
            return cell
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "CardCell", for: indexPath) as! CardCell
            cell.cardNumberLabel.text = "****-****-****-" + self.cards[indexPath.row - 1].cardLastFour!
            
            if self.isPayment{
                cell.selectButton.tag = self.cards[indexPath.row - 1].id!
                cell.selectButton.addTarget(self, action: #selector(self.selectCard(_:)), for: .touchUpInside)
                cell.buttonWidth.constant = 24
                if self.selectedId == self.cards[indexPath.row - 1].id!{
                    cell.selectButton.setImage(#imageLiteral(resourceName: "kissclipart-yes-icon-clipart-computer-icons-clip-art-c0fb4dd5a5bf0bf1"), for: .normal)
                }else{
                    cell.selectButton.setImage(nil, for: .normal)
                }
            }else{
                cell.selectButton.tag = self.cards[indexPath.row - 1].id!
                cell.selectButton.addTarget(self, action: #selector(self.removeCard(_:)), for: .touchUpInside)
                cell.buttonWidth.constant = 95
                cell.selectButton.cornerRadius(radius: 12, width: 1, color: #colorLiteral(red: 1, green: 0.1129097704, blue: 0.04416534405, alpha: 1))
                
                cell.selectButton.setTitleColor(#colorLiteral(red: 1, green: 0.1129097704, blue: 0.04416534405, alpha: 1), for: .normal)
                cell.selectButton.setImage(nil, for: .normal)
                cell.selectButton.setTitle("Удалить", for: .normal)
            }
            
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if self.isPayment{
            return self.cards.count + 3
        }else{
            return self.cards.count + 1
        }
        
    }
    
    @objc func pay(_ sender: UIButton){
        if self.selectedId == 0{
            self.showAlert(title: "Пожалуйста", message: "Выберите или добавьте карту")
            return
        }
        self.startLoading()
        self.oplataByCard(serviceId: (self.service?.id!)!, amount: self.price, payCardId: "\(self.selectedId)", completionHandler: {
            succ in
            if let success = succ.success {
                if success == true {
                    print("everything is gut")
                    SuccessVC.open(vc: self, text: "Ваша оплата на прошла успешно! \nСпасибо за доверие!")
//                    let alert = UIAlertController(title: "УРА!", message: "Оплата произведена успешно! ", preferredStyle: .alert)
//                    alert.addAction(UIAlertAction(title: "Готово", style: .cancel, handler: { action in
//
//                        //self.dismiss(animated: true, completion: nil)
//                        _ = self.navigationController?.popToRootViewController(animated: true)
//                    }
//                    ))
//                    self.present(alert, animated: true)
                    
                }
                else {
                    print("everything is badd")
                    
                    let alert = UIAlertController(title: "К сожалению, что-то пошло не так", message: "Попробуйте оплатить другой картой", preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Хорошо", style: .cancel, handler: { action in
                        
                        //self.dismiss(animated: true, completion: nil)
//                        _ = self.navigationController?.popToRootViewController(animated: true)
                    }
                    ))
                    self.present(alert, animated: true)
                    
                    
                }
                
            }
            else {
                print("nihuya net")
            }
            
        })
        
    }
    
    static func open(vc: UIViewController, service : Service, partner: Partner, isPayment: Bool, price: Int){
        let viewController = CardsVC(nibName: "CardsVC", bundle: nil)
        viewController.service = service
        viewController.partner = partner
        viewController.isPayment = isPayment
        viewController.price = price
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    @objc func selectCard(_ sender: UIButton){
        self.selectedId = sender.tag
        self.tableView.reloadData()
    }
    @objc func removeCard(_ sender: UIButton){
        let id = sender.tag
        let json = ["token" : getToken(), "id" : id] as [String : AnyObject]
        self.removeCard(params: json, completionHandler: { success in
            self.getMyCards(completionHandler: { c in
                self.cards = c
                self.tableView.reloadData()
            })
        })
    }
    @objc func addCardVC(_ sender: UIButton){
        AddCardVC.open(vc: self, serv: self.service!, partner: self.partner!, price: self.price)
    }
    
}
extension CardsVC{
    
    func oplataByCard(serviceId: Int, amount:Int, payCardId : String,  completionHandler: @escaping (_ succ: OplataObj) -> ()) {
        
        let headers = [
            "Content-Type": "application/x-www-form-urlencoded",
            "Authorization" : "Bearer \(UserDefaults.standard.string(forKey: "token")!)"
        ]
        let parameters : Parameters = [
            "service_id" : serviceId,
            "amount" : amount,
            "card_id" : payCardId
        ]
        
        Alamofire.request(url + "buyTakonByCard", method: .post, parameters: parameters, headers: headers).responseObject{ (response: DataResponse<OplataObj>) in
            self.stopLoading()
            if let otvetResponse = response.result.value{
                completionHandler(otvetResponse)
            }
        }
        
        
    }
    
    
    func removeCard(params: [String : AnyObject], completionHandler: @escaping (_ params: Bool) -> ()) {
        Alamofire.request("\(url)remove-card", method: .post, parameters: params, encoding: URLEncoding.default, headers: nil).responseObject{
            (response: DataResponse<StandartResponse>) in
            if let code = response.response?.statusCode{
                if let response = response.result.value{
                    if response.success ?? false{
                        
                        completionHandler(true)
                        
                    }else{
                        completionHandler(false)
                    }
                }
            }
            
            
        }
        
    }
    func getMyCards (completionHandler: @escaping (_ cardy: [Card1]) -> ()){
        
        var allCards = [Card1]()
        
        
        print("get comments my func bastaldy")
        let headers = [
            "Content-Type": "application/x-www-form-urlencoded",
            "Authorization" : "Bearer " + getToken()
        ]
        
        Alamofire.request(url + "getCards", method: .get, headers: headers).responseObject{ (response: DataResponse<CardsObj>) in
            self.stopLoading()
            let cardsResponse = response.result.value
            
            if let cards = cardsResponse?.cards {
                
                for item in cards {
                    
                    allCards.append(item)
                    
                    
                }
                
                completionHandler(allCards)
            }
        }
    }
}

