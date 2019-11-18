//
//  PersonalDataVC.swift
//  TAKON V2
//
//  Created by root user on 10/16/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire

class PersonalDataVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    var user : User?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Личные данные"
        self.tableView.separatorStyle = .none
        self.tableView.backgroundColor = .clear
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.register(UINib(nibName: "TextFieldCell", bundle: nil), forCellReuseIdentifier: "TextFieldCell")
        self.tableView.register(UINib(nibName: "ButtonCell", bundle: nil), forCellReuseIdentifier: "ButtonCell")
        self.getProfile(completionHandler: { user in
            self.user = user
            self.tableView.reloadData()
        })
    }


    @IBOutlet var tableView: UITableView!
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 4
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        if indexPath.row == 3{
            let cell = tableView.dequeueReusableCell(withIdentifier: "ButtonCell", for: indexPath) as! ButtonCell
            cell.button.setTitle("Сохранить", for: .normal)
            cell.button.addTarget(self, action: #selector(self.savePressed(_:)), for: .touchUpInside)
            return cell
        }else{
            let cell = tableView.dequeueReusableCell(withIdentifier: "TextFieldCell", for: indexPath) as! TextFieldCell
            cell.backgroundColor = .clear
            if indexPath.row == 0{
                cell.label.text = "Фамилия"
                if let lastName = user?.lastName{
                    cell.textField.text = lastName
                }
            }
                
            else if indexPath.row == 2{
                cell.label.text = "ИИН"
                cell.textField.keyboardType = .numberPad
                if let iin = user?.iin{
                    cell.textField.text = iin
                }
            }
            else{
                cell.label.text = "Имя"
                if let firstName = user?.firstName{
                    cell.textField.text = firstName
                }
            }
            cell.textField.autocapitalizationType = .words
            return cell
        }
        
    }
    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        return UIView()
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        switch indexPath.row {
  
        case 3:
            return 120
        default:
            return 90
        }
    }
    
    @objc func savePressed(_ sender: UIButton){
        let firstNameCell = tableView.cellForRow(at: IndexPath(row: 1, section: 0)) as! TextFieldCell
        let lastNameCell = tableView.cellForRow(at: IndexPath(row: 0, section: 0)) as! TextFieldCell
        let iinCell = tableView.cellForRow(at: IndexPath(row: 2, section: 0)) as! TextFieldCell
        
        let fName = firstNameCell.textField.text
        let lName = lastNameCell.textField.text
        let iin = iinCell.textField.text
        let json = ["iin" : iin, "last_name" : lName, "first_name" : fName, "token" : getToken()] as [String : AnyObject]
        self.setProfile(params: json, completionHandler: { success in
            if success{
                self.singleVibration()
                self.showAlert(title: "Успешно", message: "Данные сохранены")
            }else{
                self.showAlert(title: "Ошибка", message: "Попробуйте позже")
            }
        })
    }
    
    static func open(vc: UIViewController){
        let viewController = PersonalDataVC(nibName: "PersonalDataVC", bundle: nil)
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
}
extension PersonalDataVC{
    
    func getProfile(completionHandler: @escaping (_ params: User) -> ()) {
        Alamofire.request("\(url)get-profile", method: .post, parameters: ["token" : getToken()], encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<UserResponse>) in
            if let code = response.response?.statusCode{
              
                if let user = response.result.value?.user{
                    completionHandler(user)
                }
                
              
            }
            
            
        }
        
    }
    
    
    func setProfile(params: [String : AnyObject], completionHandler: @escaping (_ params: Bool) -> ()) {
        Alamofire.request("\(url)set-profile", method: .post, parameters: params, encoding: URLEncoding.default, headers: nil).responseObject{
            (response: DataResponse<UserResponse>) in
            if let code = response.response?.statusCode{
                if let response = response.result.value{
                    if response.success ?? false{
                        if let user = response.user{
                            self.saveObject(object: user, key: "user")
                        }
                        completionHandler(true)
                        
                    }else{
                        completionHandler(false)
                    }
                }
            }
            
            
        }
        
    }
}
