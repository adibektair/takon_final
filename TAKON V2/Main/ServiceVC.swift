//
//  ServiceVC.swift
//  TAKON V2
//
//  Created by root user on 9/30/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import SDWebImage
import Alamofire

class ServiceVC: UIViewController, UITableViewDataSource, UITableViewDelegate, UIPickerViewDelegate, UIPickerViewDataSource {

    //Mark: variables
    var fields = [PaymentFields]()
    var id: Int?
    var service: Service?
    var users_services = [UsersServices]()
    var totalAmount : Double = 0
    var partner: Partner?
    var selectedId = 0
    let picker = UIPickerView()
    var selectedIndex = 0
    var companiesAmount = 0
    var userId = 0
    var isUse  = Bool()
    var pickerView = UIView(){
        didSet{
            self.pickerView.frame = CGRect(x: 15, y: (UIScreen.main.bounds.height / 2) - 150, width: UIScreen.main.bounds.width - 30, height: 300)
            self.pickerView.cornerRadius(radius: 24, width: 0, color: .white)
            self.pickerView.backgroundColor = .white
        }
    }
    var selectCompanyButton = UIButton(){
        didSet{
            self.selectCompanyButton.setTitle("Выбрать", for: .normal)
            self.selectCompanyButton.addTarget(self, action: #selector(self.selectCompany(_:)), for: .touchUpInside)
        }
    }
    
    
    //Mark: lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.fields = [.name, .amount, .button]
        self.title = self.service?.name!
        self.tableView.separatorStyle = .none
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.allowsSelection = false
        self.picker.delegate = self
        self.picker.dataSource = self
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
        self.tableView.register(UINib(nibName: "PaymentTVC", bundle: nil), forCellReuseIdentifier: "PaymentTVC")
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        var index = 0
        self.getTakons(json: ["service_id" : id! as AnyObject, "token" : self.getToken() as AnyObject], completionHandler: { takons in
            self.users_services = takons
            for service in self.users_services{
                if service.usersAmount! > 0{
                    self.companiesAmount += 1
                    self.selectedId = service.id!
                }
                self.totalAmount += service.usersAmount!
            }
            if self.users_services.count > 0{
                self.selectedId = self.users_services[0].id!
            }
            self.tableView.reloadData()
        })
    }
    

    //Mark: outlets
    @IBOutlet var tableView: UITableView!
    
    
    //Mark: table view
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return fields.count
    }
    

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch fields[indexPath.row] {
        case .name:
            return 35.0
        default:
            return 160.0
        }
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        switch fields[indexPath.row] {
        case .name:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.innerTextLabel.text = "Название услуги и количество"
            cell.backgroundColor = .clear
            return cell
            
        case .amount:
            let cell = tableView.dequeueReusableCell(withIdentifier: "PaymentTVC", for: indexPath) as! PaymentTVC
            cell.takonAmountLabel.text = "\(self.totalAmount) таконов"
            cell.amountTextField.keyboardType = .decimalPad
            cell.amountTextField.isUserInteractionEnabled = true
            cell.changeButton.addTarget(self, action: #selector(self.back(_:)), for: .touchUpInside)
            cell.backgroundColor = .white
            if let url = partner?.imagePath{
                let img = URL(string: imageUrl + url.encodeUrl)
                cell.logoImageView.sd_setImage(with: img, completed: nil)
            }
            cell.serviceNameLabel.text = self.service?.name!
            
            return cell
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.setTitle("Применить", for: .normal)
            cell.button.addTarget(self, action: #selector(acceptClicked(_:)), for: .touchUpInside)
            return cell
        }
    }
    
    
    // Mark: Actions
    @objc func back(_ sender: UIButton){
        self.navigationController?.popViewController(animated: true)
    }
    static func open(vc: UIViewController, id: Int, service : Service, partner: Partner, isUse: Bool, userId : Int){
        let viewController = ServiceVC(nibName: "ServiceVC", bundle: nil)
        viewController.id = id
        viewController.service = service
        viewController.partner = partner
        viewController.isUse = isUse
        viewController.userId = userId
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    @objc func acceptClicked(_ sender : UIButton ){
        if self.companiesAmount == 1{
            let cell = tableView.cellForRow(at: IndexPath(row: 1, section: 0)) as! PaymentTVC
            let amount = cell.amountTextField.text!
      
            if let amounts = Double(amount){
                
            }else{
                self.showAlert(title: "Внимание", message: "Введите корректные значения")
                return
            }
            
            if self.isUse{
                self.startLoading()
                let json = [
                    "amount": amount,
                    "takon_id": self.selectedId,
                    "user_id": self.userId,
                    "token" : self.getToken()
                    ] as [String:Any]
                self.pay(jsonObject: json, completionHandler: { response in
                    self.stopLoading()
                    if response.success!{
                        SuccessVC.open(vc: self, text: "Спасибо! Оплата  \(amount) Таконов прошла успешно! \n\nСпасибо за доверие!" )
                    }else{
                        self.showAlert(title: "Ошибка", message: "Попробуйте позже")
                    }
                })

            }else{
                QRCodeGeneratorVC.open(vc: self, id: selectedId, amount: Int(amount)!)
            }
        }else if self.companiesAmount > 1{
            self.pickerView.frame = CGRect(x: 5, y: (UIScreen.main.bounds.height / 2) - 150, width: UIScreen.main.bounds.width - 10, height: 300)
            self.pickerView.cornerRadius(radius: 24, width: 0, color: .white)
            self.pickerView.backgroundColor = .white
            self.selectCompanyButton.setTitle("Выбрать", for: .normal)
            self.selectCompanyButton.addTarget(self, action: #selector(self.selectCompany(_:)), for: .touchUpInside)
            
            self.selectCompanyButton.frame = CGRect(x: 0, y: 250, width: self.pickerView.frame.width, height: 30)
            self.selectCompanyButton.setTitleColor(#colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1), for: .normal)
            self.picker.frame = CGRect(x: 5, y: 15, width: UIScreen.main.bounds.width - 10, height: 200)
            self.pickerView.addSubview(self.picker)
            self.pickerView.addSubview(self.selectCompanyButton)
            dark.frame = self.view.frame
            dark.backgroundColor = #colorLiteral(red: 0.2549019754, green: 0.2745098174, blue: 0.3019607961, alpha: 1).withAlphaComponent(0.5)
            self.view.addSubview(dark)
            self.view.addSubview(pickerView)
        }
    }
    @objc func selectCompany(_ sender: UIButton){
        dark.removeFromSuperview()
        self.pickerView.removeFromSuperview()
        
        let amountCell = tableView.cellForRow(at: IndexPath(row: 1, section: 0)) as! PaymentTVC
        if let amount = amountCell.amountTextField.text{
            if let amounts = Double(amount){
                
            }else{
                self.showAlert(title: "Внимание", message: "Введите корректные значения")
                return
            }
            let intVal = Double(amount)!
            if intVal > self.users_services[self.selectedIndex].usersAmount!{
                self.showAlert(title: "Внимание", message: "К сожалению, у Вас недостаточно таконов")
            }else{
                if self.isUse{
                    
                    let json = [
                        "amount": intVal,
                        "takon_id": self.selectedId,
                        "user_id": self.userId,
                        "token" : self.getToken()
                        ] as [String:Any]
                    self.pay(jsonObject: json, completionHandler: { response in
                        if response.success!{
                            SuccessVC.open(vc: self, text: "Оплата прошла успешно \nСпасибо за доверие!")
                        }else{
                            self.showAlert(title: "Ошибка", message: "Попробуйте позже")
                        }
                    })
                }else{
                    QRCodeGeneratorVC.open(vc: self, id: selectedId, amount: Int(intVal))
                }
            }
        }
        
    }
    
    
    //MARK: picker view
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return self.users_services.count
    }
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let usersSerivce = users_services[row]
        self.selectedId = usersSerivce.id!
        self.selectedIndex = row
    }
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        let userService = users_services[row]
        let date = Date(timeIntervalSince1970: TimeInterval(Int(userService.deadline!)!))
        let dateFormatter = DateFormatter()
        dateFormatter.timeZone = TimeZone(abbreviation: "GMT") //Set timezone that you want
        dateFormatter.locale = NSLocale.current
        dateFormatter.dateFormat = "dd.MM.yyyy" //Specify your format that you want
        let strDate = dateFormatter.string(from: date)
        return userService.company! + " \(userService.usersAmount!)" + " до: " + strDate
    }
   
}
extension UIViewController{
    func getTakons(json: [String: AnyObject], completionHandler: @escaping (_ params: [UsersServices]) -> ()) {
        Alamofire.request("\(url)gettakons", method: .post, parameters: json, encoding: URLEncoding.default, headers: nil).responseObject{
            (response: DataResponse<MainTakons>) in
            if response.response?.statusCode != nil {
                if (response.response?.statusCode)! < 350{
                    let info = response.result.value
                    completionHandler(info!.takons!)
                }
            }
        }
    }
    func pay(jsonObject: [String : Any], completionHandler: @escaping (_ params: Response) -> ()) {
   
        Alamofire.request("\(url)scan", method: .post, parameters: jsonObject, encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<Response>) in
            if let responseCode = response.response?.statusCode{
                if responseCode == 200{
                    let info = response.result.value
                    completionHandler(info!)
                }else{
                    self.showAlert(title: "Ошибка", message: "Обратитесь к администратору")
                }
            }
        }
        
    }
    
}
