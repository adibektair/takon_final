//
//  ProfileVC.swift
//  TAKON V2
//
//  Created by root user on 10/16/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
enum ProfileFields {
    case header
    case notifications
    case payment
    case data
    case share
}

class ProfileVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    let titles = ["Уведомления",  "Методы оплаты", "Сменить личные данные", "Пригласить друзей"]
    let icons : [UIImage] = [#imageLiteral(resourceName: "bell"), #imageLiteral(resourceName: "tenge"), #imageLiteral(resourceName: "user"), #imageLiteral(resourceName: "invite")]
    let fields : [ProfileFields] = [.header, .notifications, .payment, .data, .share]
    
    override func viewDidLoad() {
        self.title = "Профиль"
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = false
        } else {
            // Fallback on earlier versions
        }
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Выйти", style: .plain, target: self, action: #selector(self.logout))
        navigationItem.rightBarButtonItem?.tintColor = #colorLiteral(red: 1, green: 0.140542564, blue: 0.118414846, alpha: 1)
        
        super.viewDidLoad()
        let user = getSavedObject(forKey: "user") as? User
        if let fName = user?.firstName, let lname = user?.lastName{
            self.nameLabel.text = lname + " " + fName
        }else{
            self.nameLabel.text = "Ваше имя"
        }
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
        self.tableView.register(UINib(nibName: "ProfileCell", bundle: nil), forCellReuseIdentifier: "ProfileCell")
        self.tableView.backgroundColor = .clear
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.phoneLabel.text = "+" + (user?.phone!)!
        // Do any additional setup after loading the view.
    }

    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var phoneLabel: UILabel!
    @IBOutlet var tableView: UITableView!
    
    @objc func logout(){
        
        let deleteAlert = UIAlertController(title: "Вы уверены, что хотите выйти?", message: "Все Ваши данные будут удалены с этого устройства", preferredStyle: UIAlertController.Style.actionSheet)
        
        let generateQr = UIAlertAction(title: "Да", style: .destructive) { (action: UIAlertAction) in
            
            let defaults = UserDefaults.standard
            let dictionary = defaults.dictionaryRepresentation()
            dictionary.keys.forEach { key in
                defaults.removeObject(forKey: key)
            }
            
            let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
            let newViewController = storyBoard.instantiateViewController(withIdentifier: "start")
            self.present(newViewController, animated: false, completion: nil)
        }
        let cancel = UIAlertAction(title: "Отмена", style: .cancel) { (action: UIAlertAction) in
            
           
        }
        
        deleteAlert.addAction(generateQr)
        deleteAlert.addAction(cancel)

        if UIDevice.current.userInterfaceIdiom == .pad {
            deleteAlert.popoverPresentationController!.sourceView = self.view
            deleteAlert.popoverPresentationController!.sourceRect = CGRect(x: self.view.bounds.size.width / 2.0, y: self.view.bounds.size.height / 2.0, width: 1.0, height: 1.0)
        }
        
        self.present(deleteAlert, animated: true, completion: nil)

    }
    
    
    static func open(vc: UIViewController){
        let viewController = ProfileVC(nibName: "ProfileVC", bundle: nil)
    
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.fields.count
    }
    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
           return UIView()
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if indexPath.row == 0{
            return 35.0
        }else{
            return 56.0
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let i = indexPath.row
        switch fields[i] {
        case .header:
            let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC", for: indexPath) as! HeaderTVC
            cell.backgroundColor = .clear
            cell.innerTextLabel.text = "Настройки"
            return cell
        default:
            let cell = tableView.dequeueReusableCell(withIdentifier: "ProfileCell", for: indexPath) as! ProfileCell
            cell.innerTextLabel.text = self.titles[i - 1]
            cell.iconImageView.image = icons[i - 1]
            return cell
            

        }
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 1:
            NotificationsVC.open(vc: self)
        case 2:
            CardsVC.open(vc: self, service: Service(), partner: Partner(), isPayment: false, price: 0)
        case 3:
            PersonalDataVC.open(vc: self)
        default:
            let text = "Цифровые талоны в твоём телефоне - http://onelink.to/uqwqaf"
            
            // set up activity view controller
            let textToShare = [ text ]
            let activityViewController = UIActivityViewController(activityItems: textToShare, applicationActivities: nil)
            activityViewController.popoverPresentationController?.sourceView = self.view // so that iPads won't crash
            
            // exclude some activity types from the list (optional)
            activityViewController.excludedActivityTypes = [ UIActivity.ActivityType.airDrop, UIActivity.ActivityType.postToFacebook ]
            
            // present the view controller
            self.present(activityViewController, animated: true, completion: nil)
        }
    }
}











