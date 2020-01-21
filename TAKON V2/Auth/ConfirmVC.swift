//
//  ConfirmVC.swift
//  TAKON V2
//
//  Created by root user on 9/23/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
import ObjectMapper


class ConfirmVC: UIViewController, UITextFieldDelegate {

    var phone: String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Подтверждение"
        self.firtsTextField.becomeFirstResponder()
        self.firtsTextField.delegate = self
        self.secondTextField.delegate = self
        self.thirdTextField.delegate = self
        self.fourthTextField.delegate = self
        firtsTextField.addTarget(self, action: #selector(textFieldDidChange(textField:)), for: .editingChanged)
        secondTextField.addTarget(self, action: #selector(textFieldDidChange(textField:)), for: .editingChanged)
        thirdTextField.addTarget(self, action: #selector(textFieldDidChange(textField:)), for: .editingChanged)
        fourthTextField.addTarget(self, action: #selector(textFieldDidChange(textField:)), for: .editingChanged)

    }


    // Mark: Outlets
    @IBOutlet var titleLabel: UILabel!{
        didSet{
            self.titleLabel.text = "СМС-код отправлен на \n+7 \(phone!).\nПожалуйста, введите полученный код для подтверждения номера телефона."
        }
    }
    @IBOutlet weak var firtsTextField: UITextField!
    @IBOutlet weak var secondTextField: UITextField!
    @IBOutlet weak var thirdTextField: UITextField!
    @IBOutlet weak var fourthTextField: UITextField!
    @IBOutlet var firstView: UIView!{
        didSet{
            self.firstView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    
    @IBOutlet var secondView: UIView!{
        didSet{
            self.secondView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    
    @IBOutlet var thirdView: UIView!{
        didSet{
            self.thirdView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    
    @IBOutlet var fourthView: UIView!{
        didSet{
            self.fourthView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    
    
    @IBAction func sendCodeButtonPressed(_ sender: Any) {
        
    }
    
    internal func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        guard let text = textField.text else { return true }
        let newLength = text.count + string.count - range.length
        if textField != firtsTextField{
            let  char = string.cString(using: String.Encoding.utf8)!
            let isBackSpace = strcmp(char, "\\b")
            print("IS BACK", isBackSpace)
            if (isBackSpace == -92) {
                clear()
            }
        }
        return newLength <= 1 // Bool
    }
    
    @objc func textFieldDidChange(textField: UITextField) {
        if textField == firtsTextField{
            if textField.text!.count > 0{
                self.secondTextField.becomeFirstResponder()
            }
        }
        else if textField == secondTextField{
            if textField.text!.count > 0{
                self.thirdTextField.becomeFirstResponder()
            }
        }
        else if textField == thirdTextField{
            if textField.text!.count > 0{
                self.fourthTextField.becomeFirstResponder()
            }
        }else if textField == fourthTextField{
            if textField.text!.count > 0{
                // log in
                if !(firtsTextField.text?.isEmpty)! && !(secondTextField.text?.isEmpty)! && !(thirdTextField.text?.isEmpty)!{
                    if let code = Int(firtsTextField.text! + secondTextField.text! + thirdTextField.text! + fourthTextField.text!){
                        let phoneNumber = self.phone?.filter("1234567890".contains)
                        let json = ["phone" : "7" + phoneNumber!, "password" : code] as Parameters
                        self.logIn(jsonObject: json, completionHandler: { success in
                            if success{
                                self.singleVibration()
                                let storyBoard: UIStoryboard = UIStoryboard(name: "Storyboard", bundle: nil)
                                let newViewController = storyBoard.instantiateViewController(withIdentifier: "main")
                                newViewController.modalPresentationStyle = .fullScreen //or .overFullScreen for transparency

                                self.present(newViewController, animated: true, completion: nil)
                            }else{
                                self.clear()
                                self.showAlert(title: "Ошибка", message: "Перепроверьте правильность кода")
                            }
                        })
                        
                    }
                    else{
                        
                        self.showAlert(title: "Внимание", message: "Некорректный код")
                    }
                    
                }else{
                    
                    self.showAlert(title: "Внимание", message: "Некорректный код")
                }
                
                
            }
        }
    }
    
    func clear(){
        firtsTextField.becomeFirstResponder()
        firtsTextField.text = ""
        secondTextField.text = ""
        thirdTextField.text = ""
        fourthTextField.text = ""
    }

    static func open(vc: UIViewController, phone: String){
        let viewController = ConfirmVC(nibName: "ConfirmVC", bundle: nil)
        viewController.phone = phone
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
}
extension ConfirmVC{
    func logIn(jsonObject: [String : Any], completionHandler: @escaping (Bool) -> ()){
        Alamofire.request("\(url)m_login", method: .post, parameters: jsonObject, encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<RootClass>) in
            if let code = response.response?.statusCode{
            
                if let user = response.result.value?.user{
                    UserDefaults.standard.set(user.token!, forKey: "token")
                    self.saveObject(object: user, key: "user")
                    completionHandler(true)
                }else{
                    completionHandler(false)
                }
            }
            
            
        }
//        Alamofire.request(url + "m_login", method: .post, parameters: jsonObject, encoding: URLEncoding.default)
//            .responseJSON { response in
//                print(response)
//                if let code = (response.response?.statusCode) {
//                    if code == 200{
//                        if let result = response.result.value{
//                            let JSON = result as! NSDictionary
//                            if let token = (JSON as! [String : AnyObject])["token"]{
//                                UserDefaults.standard.set(token as! String, forKey: "token")
//                            }
//                            if let user = (JSON as! [String: AnyObject])["user"]{
//                                if let us = user as? User{
//                                    self.saveObject(object: us, key: "user")
//                                }
//                            }
//                            completionHandler(true)
//                        }
//                    }else{
//                        completionHandler(false)
//                    }
//                }
//        }
    }
}



class RootClass : NSObject, NSCoding, Mappable{
    
    var success : Bool?
    var token : String?
    var user : User?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return RootClass()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        success <- map["success"]
        token <- map["token"]
        user <- map["user"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        token = aDecoder.decodeObject(forKey: "token") as? String
        user = aDecoder.decodeObject(forKey: "user") as? User
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        if token != nil{
            aCoder.encode(token, forKey: "token")
        }
        if user != nil{
            aCoder.encode(user, forKey: "user")
        }
        
    }
    
}

class User : NSObject, NSCoding, Mappable{
    
    var createdAt : String?
    var firstName : String?
    var id : Int?
    var iin : String?
    var lastName : String?
    var name : String?
    var phone : String?
    var platform : Int?
    var pushId : String?
    var token : String?
    var updatedAt : String?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return User()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        createdAt <- map["created_at"]
        firstName <- map["first_name"]
        id <- map["id"]
        iin <- map["iin"]
        lastName <- map["last_name"]
        name <- map["name"]
        phone <- map["phone"]
        platform <- map["platform"]
        pushId <- map["push_id"]
        token <- map["token"]
        updatedAt <- map["updated_at"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        firstName = aDecoder.decodeObject(forKey: "first_name") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        iin = aDecoder.decodeObject(forKey: "iin") as? String
        lastName = aDecoder.decodeObject(forKey: "last_name") as? String
        name = aDecoder.decodeObject(forKey: "name") as? String
        phone = aDecoder.decodeObject(forKey: "phone") as? String
        platform = aDecoder.decodeObject(forKey: "platform") as? Int
        pushId = aDecoder.decodeObject(forKey: "push_id") as? String
        token = aDecoder.decodeObject(forKey: "token") as? String
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if createdAt != nil{
            aCoder.encode(createdAt, forKey: "created_at")
        }
        if firstName != nil{
            aCoder.encode(firstName, forKey: "first_name")
        }
        if id != nil{
            aCoder.encode(id, forKey: "id")
        }
        if iin != nil{
            aCoder.encode(iin, forKey: "iin")
        }
        if lastName != nil{
            aCoder.encode(lastName, forKey: "last_name")
        }
        if name != nil{
            aCoder.encode(name, forKey: "name")
        }
        if phone != nil{
            aCoder.encode(phone, forKey: "phone")
        }
        if platform != nil{
            aCoder.encode(platform, forKey: "platform")
        }
        if pushId != nil{
            aCoder.encode(pushId, forKey: "push_id")
        }
        if token != nil{
            aCoder.encode(token, forKey: "token")
        }
        if updatedAt != nil{
            aCoder.encode(updatedAt, forKey: "updated_at")
        }
        
    }
    
}
