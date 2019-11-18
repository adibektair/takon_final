//
//  SendFriendVC.swift
//  TAKON V2
//
//  Created by root user on 10/2/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import ContactsUI
import Alamofire

class SendFriendVC: UIViewController, UITableViewDelegate, UITableViewDataSource, CNContactPickerDelegate, UIPickerViewDelegate, UIPickerViewDataSource {

    //MARK: variables
    var id: Int?
    var service: Service?
    var partner: Partner?
    var fields = [PaymentFields]()
    var users_services = [UsersServices]()
    var totalAmount : Double = 0
    var selectedId = 0
    var companiesAmount = 0
    let picker = UIPickerView()
    var selectedIndex = 0
    var phoneNumber = ""
    
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
    
    //MARK: lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.fields = [.name, .amount, .phone, .phoneNumber, .button]
        self.title = "Передать другу"
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
        self.tableView.register(UINib(nibName: "PaymentTVC", bundle: nil), forCellReuseIdentifier: "PaymentTVC")
        self.tableView.register(UINib(nibName: "PhoneNumberTVC", bundle: nil), forCellReuseIdentifier: "PhoneNumberTVC")
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        self.tableView.allowsSelection = false
        self.tableView.separatorStyle = .none
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.reloadData()
        self.picker.delegate = self
        self.picker.dataSource = self
        
        self.getTakons(json: ["service_id" : id! as AnyObject, "token" : self.getToken() as AnyObject], completionHandler: { takons in
            self.users_services = takons
            var index = 0
            for service in self.users_services{
                index += 1
                if service.usersAmount! > 0{
                    self.companiesAmount += 1
                    self.selectedId = service.id!
                }
                self.totalAmount += service.usersAmount!
            }
            self.tableView.reloadData()
        })
    }


    //MARK: outlets
    @IBOutlet var tableView: UITableView!
    
    //MARK: actions
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
            cell.amountTextField.keyboardType = .numberPad
            cell.changeButton.addTarget(self, action: #selector(self.back(_:)), for: .touchUpInside)
            cell.amountTextField.isUserInteractionEnabled = true
            cell.backgroundColor = .white
            if let url = partner?.imagePath{
                let img = URL(string: imageUrl + url.encodeUrl)
                cell.logoImageView.sd_setImage(with: img, completed: nil)
            }
            cell.serviceNameLabel.text = self.service?.name!
            
            return cell
        case .phone:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.innerTextLabel.text = "Получатель"
            cell.backgroundColor = .clear
            return cell
        case .phoneNumber:
            let cell = tableView.dequeueReusableCell(withIdentifier: "PhoneNumberTVC", for: indexPath) as! PhoneNumberTVC
            cell.getFromContactsButton.addTarget(self, action: #selector(self.getContacts(_:)), for: .touchUpInside)
            cell.getFromContactsButton.setTitle("Выбрать из контактов телефона", for: .normal)
            cell.phoneNumberTextField.isUserInteractionEnabled = true
            cell.phoneNumberTextField.keyboardType = .phonePad
            return cell
            
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.addTarget(self, action: #selector(self.sendTakons(_:)), for: .touchUpInside)
            cell.button.setTitle("Отправить", for: .normal)
            return cell
            
        }
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.fields.count
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch fields[indexPath.row] {
        case .amount:
            return 160.0
        case .phoneNumber:
            return 180.0
        case .button:
            return 70.0
            
        default:
            return 35.0
        }
    }
    
    //MARK: actions
    @objc func back(_ sender: UIButton){
        self.navigationController?.popViewController(animated: true)
    }
    
    @objc func getContacts(_ sender: UIButton){
        let contactPicker = CNContactPickerViewController()
        contactPicker.delegate = self
        contactPicker.displayedPropertyKeys =
            [CNContactGivenNameKey
                , CNContactPhoneNumbersKey]
        self.present(contactPicker, animated: true, completion: nil)
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
                let json = ["token" : getToken(), "takon_id" : self.selectedId, "phone" : self.phoneNumber, "amount" : intVal] as [String : AnyObject]
                self.startLoading()
                self.sendFriend(jsonObject: json, completionHandler: { success in
                    self.stopLoading()
                    if success{
                         SuccessVC.open(vc: self, text: "Ваши Таконы в количестве \(intVal) были успешно доставлены. \n\nСпасибо за доверие!" )
//                        self.showAlert(title: "Спасибо!", message: "Ваши таконы были успешно доставлены")
                    }else{
                        self.showAlert(title: "Произошла ошибка", message: "Перепроверьте правильность данных")
                    }
                })
            }
        }
        
    }
    @objc func sendTakons(_ sender: UIButton){
        let amountCell = tableView.cellForRow(at: IndexPath(row: 1, section: 0)) as! PaymentTVC
        let amount = amountCell.amountTextField.text
        if amount == "" || amount == nil{
            self.showAlert(title: "Ошибка", message: "Внимание, введите количество таконов, которoе хотите передать")
            return
        }
        let cell = self.tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! PhoneNumberTVC
        if cell.phoneNumberTextField.text != "" && cell.phoneNumberTextField.text != nil{
            var phone = cell.phoneNumberTextField.text!.filter("0123456789".contains)
            if phone.prefix(1) == "8"{
                let str = phone.replacingOccurrences(of: "(", with: "", options: NSString.CompareOptions.literal, range: nil)
                let str1 = str.replacingOccurrences(of: ")", with: "", options: NSString.CompareOptions.literal, range: nil)
                let str2 = str1.replacingOccurrences(of: "-", with: "", options: NSString.CompareOptions.literal, range: nil)
                let str3 = str2.replacingOccurrences(of: " ", with: "", options: NSString.CompareOptions.literal, range: nil)
                phone = "7" + str3.dropFirst()
            }
            self.phoneNumber = phone
            
            if self.companiesAmount > 1{
                self.pickerView.frame = CGRect(x: 5, y: (UIScreen.main.bounds.height / 2) - 150, width: UIScreen.main.bounds.width - 10, height: 300)
                self.pickerView.cornerRadius(radius: 24, width: 0, color: .white)
                self.pickerView.backgroundColor = .white
                self.selectCompanyButton.setTitle("Выбрать", for: .normal)
                self.selectCompanyButton.addTarget(self, action: #selector(self.selectCompany(_:)), for: .touchUpInside)
                self.selectCompanyButton.setTitleColor(#colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1), for: .normal)
                self.selectCompanyButton.frame = CGRect(x: 0, y: 250, width: self.pickerView.frame.width, height: 30)
                self.picker.frame = CGRect(x: 5, y: 15, width: UIScreen.main.bounds.width - 10, height: 200)
                self.pickerView.addSubview(self.picker)
                self.pickerView.addSubview(self.selectCompanyButton)
                dark.frame = self.view.frame
                dark.backgroundColor = #colorLiteral(red: 0.2549019754, green: 0.2745098174, blue: 0.3019607961, alpha: 1).withAlphaComponent(0.5)
                self.view.addSubview(dark)
                self.view.addSubview(pickerView)
                
            }else if self.companiesAmount == 1{
                
                let json = ["token" : getToken(), "takon_id" : self.selectedId, "phone" : phone, "amount" : amount!] as [String : AnyObject]
                self.sendFriend(jsonObject: json, completionHandler: { success in
                    if success{
                        SuccessVC.open(vc: self, text: "Ваши Таконы в количестве \(amount!) были успешно доставлены. \n\nСпасибо за доверие!" )
//                        self.showAlert(title: "Спасибо!", message: "Ваши таконы были успешно доставлены")
                    }else{
                        self.showAlert(title: "Произошла ошибка", message: "Перепроверьте правильность данных")
                    }
                })
            }
            
        }else{
            self.showAlert(title: "Ошибка", message: "Введите номер телефона получателя или выберите из списка Ваших контактов")
        }
    }
    
    static func open(vc: UIViewController, id: Int, service : Service, partner: Partner){
        let viewController = SendFriendVC(nibName: "SendFriendVC", bundle: nil)
        viewController.id = id
        viewController.service = service
        viewController.partner = partner
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
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
    
    //MARK: contacts picker
    func contactPicker(_ picker: CNContactPickerViewController,
                       didSelect contactProperty: CNContactProperty) {
        
    }
    
    func contactPicker(_ picker: CNContactPickerViewController, didSelect contact: CNContact) {
        // You can fetch selected name and number in the following way
        
        // user name
        let userName:String = contact.givenName
        
        // user phone number
        let userPhoneNumbers:[CNLabeledValue<CNPhoneNumber>] = contact.phoneNumbers
        let firstPhoneNumber:CNPhoneNumber = userPhoneNumbers[0].value
        
        
        // user phone number string
        let primaryPhoneNumberStr:String = firstPhoneNumber.stringValue
        
        print(primaryPhoneNumberStr)
        let cell = self.tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! PhoneNumberTVC
        cell.phoneNumberTextField.text = primaryPhoneNumberStr
        cell.nameLabel.text = userName
    }
    
    func contactPickerDidCancel(_ picker: CNContactPickerViewController) {
        
    }
}
extension SendFriendVC{
    func sendFriend(jsonObject: [String : AnyObject], completionHandler: @escaping (Bool) -> ()){
        Alamofire.request(url + "send_takon", method: .post, parameters: jsonObject, encoding: URLEncoding.default, headers: nil)
            .responseJSON { response in
                if let code = response.response?.statusCode{
                    if code == 200{
                        if let result = response.result.value{
                            let JSON = result as! NSDictionary
                            completionHandler(true)
                        }
                    }else{
                        completionHandler(false)
                    }
                }
                print(response)
        }
    }
}
