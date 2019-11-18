//
//  AddCardVC.swift
//  TAKON V2
//
//  Created by root user on 10/10/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import AnyFormatKit
import Alamofire

class AddCardVC: UIViewController, UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate {
    var cryptoCrypt : String?
    var cardStr = "4111111111111111"
    var cvv = "019"
    var expDate = "08/21"
    var apiPublicID = "pk_0ad5acde2f593df7c5a63c9c27807"
    var titles = ["Имя на карте", "Номер карты", "Дата истечения карты", "Код безопасности"]
    var placeholders = ["Имя", "Номер карты", "04/22", "Трехзначное число с обратной стороны карты"]
    var service: Service?
    var partner: Partner?
    var price = 0
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.tableFooterView = UIView()
        self.tableView.allowsSelection = false
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.separatorStyle = .none
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        self.tableView.register(UINib(nibName: "TextFieldCell", bundle: nil), forCellReuseIdentifier: "TextFieldCell")
        
    }

    @IBOutlet var tableView: UITableView!
    
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 90
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 5
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        if indexPath.row == 4{
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.setTitle("Оплатить", for: .normal)
            cell.button.addTarget(self, action: #selector(self.pay(_:)), for: .touchUpInside)
            cell.backgroundColor = .clear
            return cell
        }else{
            let cell = tableView.dequeueReusableCell(withIdentifier: "TextFieldCell", for: indexPath) as! TextFieldCell
            cell.textField.placeholder = placeholders[indexPath.row]
            cell.label.text = titles[indexPath.row]
            if indexPath.row == 3{
                cell.textField.isSecureTextEntry = true
                
                cell.textField.keyboardType = .numberPad

            }
            if indexPath.row == 1{
                cell.textField.keyboardType = .numberPad
            }
            if indexPath.row == 0{
                cell.textField.autocapitalizationType = .allCharacters
            }
            if indexPath.row == 2{
                cell.textField.keyboardType = .numberPad
                cell.textField.delegate = self
            }
            cell.backgroundColor = .clear
            return cell
        }
        
    }

    static func open(vc: UIViewController, serv: Service, partner: Partner, price: Int){
        let viewController = AddCardVC(nibName: "AddCardVC", bundle: nil)
        viewController.service = serv
        viewController.partner = partner
        viewController.price = price
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
   
    @objc func pay(_ sender: UIButton){
        let numberCell = tableView.cellForRow(at: IndexPath(row: 1, section: 0)) as! TextFieldCell
        let number = numberCell.textField.text
        
        let nameCell = tableView.cellForRow(at: IndexPath(row: 0, section: 0)) as! TextFieldCell
        let name = nameCell.textField.text
        
        let codeCell = tableView.cellForRow(at: IndexPath(row: 3, section: 0)) as! TextFieldCell
        let code = codeCell.textField.text
        
        let dateCell = tableView.cellForRow(at: IndexPath(row: 2, section: 0)) as! TextFieldCell
        let date = dateCell.textField.text
        
        if number != nil && name != nil && code != nil && date != nil{
            var ipAddress : String?
            if let ip = getIPAddress(){
                ipAddress = ip
            }else{
                ipAddress = "123.123.123.123"
            }
            let month = date!.prefix(2)
            let year = date!.suffix(2)
            let dateString = String(year) + String(month)
            
            let cryptoCrypt = CPService().makeCardCryptogramPacket(number!, andExpDate: dateString, andCVV: code!, andStorePublicID: apiPublicID)
         
            self.startLoading()
            oplataTakon(serviceId: (self.service?.id!)!, ipAddress: ipAddress!, amount: price, name: name!, cryptogram: cryptoCrypt!, completionHandler: {
                succ in
                self.stopLoading()
                if let success = succ.success {
                    
                    if success == true {
                        print("everything is gut")
                        
                        let alert = UIAlertController(title: "УРА!", message: "Оплата произведена успешно! ", preferredStyle: .alert)
                        alert.addAction(UIAlertAction(title: "Готово", style: .cancel, handler: { action in
                            
                            //self.dismiss(animated: true, completion: nil)
                            _ = self.navigationController?.popToRootViewController(animated: true)
                        }
                        ))
                        self.present(alert, animated: true)
                        
                    }
                    else {
                        
                        let webView = UIWebView()
                        webView.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height)
                        self.view.addSubview(webView)
                        
                        let newString = succ.PaReq!.replacingOccurrences(of: "+", with: "%2B", options: .literal, range: nil)
                        let param1 = "\(succ.TransactionId!)" + "&PaReq=" + newString
                        let param2 = "&url=" + succ.AcsUrl!
                        let urrString = "http://takon.org/payment?TransactionId=" + param1 + param2
                        let url = URL(string: urrString)
                        let req = URLRequest(url: url!)
                        webView.loadRequest(req)
                        
                    }
                    
                }
                else {
                    print("nihuya net")
                }
                
            })
            
        }else{
            self.showAlert(title: "Внимание", message: "Заполните все поля")
        }
        
    }

    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if (textField.text?.count == 2){
            //Handle backspace being pressed
            if !(string == "") {
                // append the text
                textField.text = (textField.text)! + "/"
            }
        }
            // check the condition not exceed 9 chars
        return !(textField.text!.count > 4 && (string.count ) > range.length)
    }
    
    
    func getIPAddress() -> String? {
        var address: String?
        var ifaddr: UnsafeMutablePointer<ifaddrs>? = nil
        if getifaddrs(&ifaddr) == 0 {
            var ptr = ifaddr
            while ptr != nil {
                defer { ptr = ptr?.pointee.ifa_next }
                
                let interface = ptr?.pointee
                let addrFamily = interface?.ifa_addr.pointee.sa_family
                if addrFamily == UInt8(AF_INET) || addrFamily == UInt8(AF_INET6) {
                    
                    if let name: String = String(cString: (interface?.ifa_name)!), name == "en0" {
                        var hostname = [CChar](repeating: 0, count: Int(NI_MAXHOST))
                        getnameinfo(interface?.ifa_addr, socklen_t((interface?.ifa_addr.pointee.sa_len)!), &hostname, socklen_t(hostname.count), nil, socklen_t(0), NI_NUMERICHOST)
                        address = String(cString: hostname)
                    }
                }
            }
            freeifaddrs(ifaddr)
        }
        return address
    }
}
extension AddCardVC{
    func oplataTakon(serviceId: Int, ipAddress : String, amount:Int, name: String, cryptogram: String, completionHandler: @escaping (_ succ: OplataObj) -> ()){
        
        let headers = [
            "Content-Type": "application/x-www-form-urlencoded",
            "Authorization" : "Bearer \(UserDefaults.standard.string(forKey: "token")!)"
        ]
        
        let parameters : Parameters = [
            "serviceId" : serviceId,
            "ip" : ipAddress,
            "amount" : amount,
            "name" : name,
            "cryptogram" : cryptogram
        ]
        
        
        Alamofire.request(url + "pay", method: .post, parameters: parameters, headers: headers).responseObject{ (response: DataResponse<OplataObj>) in
            
            if let otvetResponse = response.result.value{
                completionHandler(otvetResponse)
            }else{
                self.stopLoading()
                self.showAlert(title: "Произошла ошибка", message: "")
            }
        }
    }
}
