//
//  ViewController.swift
//  TAKON V2
//
//  Created by root user on 9/17/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
let url = "https://takon.org/api/"

class ViewController: UIViewController, UITextFieldDelegate {

    // Mark: Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.hideKeyboardWhenTappedAround()
        self.phoneNumberTextField.delegate = self
        self.navigationController?.navigationBar.isHidden = true
    }
    override func viewWillDisappear(_ animated: Bool) {
        self.navigationController?.navigationBar.isHidden = false
    }
    // Mark: Outlets
    @IBOutlet var takonView: UIView!{
        didSet{
            self.takonView.layer.masksToBounds = true
            self.takonView.layer.cornerRadius = 12
        }
    }
    @IBOutlet var textFieldView: UIView!{
        didSet{
            self.textFieldView.layer.masksToBounds = true
            self.textFieldView.layer.cornerRadius = 8
            self.textFieldView.layer.borderWidth = 0.5
            self.textFieldView.layer.borderColor = UIColor(red: 0.79, green: 0.82, blue: 0.85, alpha: 1).cgColor
        }
    }
    @IBOutlet var phoneNumberTextField: UITextField!{
        didSet{
            self.phoneNumberTextField.keyboardType = .phonePad
        }
    }
    @IBOutlet var continueButton: UIButton!{
        didSet{
            self.continueButton.layer.masksToBounds = true
            self.continueButton.layer.cornerRadius = 8
        }
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        var fullString = textField.text ?? ""
        fullString.append(string)
        if range.length == 1 {
            textField.text = format(phoneNumber: fullString, shouldRemoveLastDigit: true)
        } else {
            textField.text = format(phoneNumber: fullString)
        }
        return false
    }
    
    
    // Mark: Actions
    @IBAction func continueButtonClicked(_ sender: Any) {
        if phoneNumberTextField.text!.isEmpty{
            self.showAlert(title: "Внимание", message: "Введите номер телефона")
            return
        }
        
        let unfiltered = phoneNumberTextField.text!
        
        // Array of Characters to remove
        let removal: [Character] = ["(", " ", ")","+", "-"]
        
        // turn the string into an Array
        let unfilteredCharacters = unfiltered
        
        // return an Array without the removal Characters
        let filteredCharacters = unfilteredCharacters.filter { !removal.contains($0) }
        
        // build a String with the filtered Array
        let filtered = String(filteredCharacters)
        let json = ["phone" : "7" + filtered] as Parameters
        self.startLoading()
        self.register(jsonObject: json, completionHandler: { success in
            self.singleVibration()
            ConfirmVC.open(vc: self, phone: self.phoneNumberTextField.text!)
        })
        
        
    }
    

}

extension ViewController{
    func register(jsonObject: [String : Any], completionHandler: @escaping (Bool) -> ()){
        Alamofire.request(url + "m_register", method: .post, parameters: jsonObject, encoding: URLEncoding.default)
            .responseJSON { response in
                print(response)
                if let code = response.response?.statusCode{
                    self.stopLoading()
                    if code == 200{
                        if let result = response.result.value{
                            let JSON = result as! NSDictionary
                            completionHandler(true)
                        }
                    }
                    else{
                        completionHandler(false)
                    }
                }else{
                    self.stopLoading()
                    self.showAlert(title: "Внимание", message: "Отсутствует соединение с интернетом")
                }
                
        }
    }
}
