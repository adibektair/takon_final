//
//  CompanyVC.swift
//  TAKON V2
//
//  Created by root user on 9/27/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire

class CompanyVC: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    //MARK: variables
    var id : Int?
    var partner : Partner?
    var services = [Service]()
    var isUse = Bool()
    var userId = 0
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = false
        } else {
            // Fallback on earlier versions
        }
        self.title = self.partner?.name!
       
        self.tableView.rowHeight = 183
        self.tableView.allowsSelection = false
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.register(UINib(nibName: "CompanyTVC", bundle: nil), forCellReuseIdentifier: "cell")
        
        
    }
    override func viewWillAppear(_ animated: Bool) {
        let infoButton = UIBarButtonItem(image: #imageLiteral(resourceName: "info"), style: .plain, target: self, action: #selector(action(sender:)))
        self.navigationItem.rightBarButtonItem = infoButton
        
        self.tabBarController?.tabBar.isHidden = true
        self.getOrganizationInfo(json: ["partner_id" : self.id!] as [String: AnyObject], completionHandler: { services in
            self.services = services
            self.tableView.reloadData()
        })
    }
    
    //MARK: outlets
    @IBOutlet var tableView: UITableView!
    @IBOutlet var segmentedControl: UISegmentedControl!
    

    
    //MARK: actions
    @objc func action(sender: UIBarButtonItem) {
        MapViewController.open(vc: self, partner: self.partner!)
    }
    static func open(vc: UIViewController, id: Int, partner : Partner, isUse: Bool, userId : Int){
        let viewController = CompanyVC(nibName: "CompanyVC", bundle: nil)
        viewController.id = id
        viewController.partner = partner
        viewController.isUse = isUse
        viewController.userId = userId
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
    
    // MARK: table view
    func numberOfSections(in tableView: UITableView) -> Int {
        return self.services.count
    }
    
    // There is just one row in every section
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
  
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 183.0
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 16.0
    }
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let view = UIView()
        view.backgroundColor = .clear
        return view
    }
    
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! CompanyTVC
        let service = self.services[indexPath.section]
        cell.nameLabel.text = service.name!
        if let amount = service.usersAmount{
            cell.amountLabel.text =  "\(amount) таконов"
        }else{
            cell.amountLabel.text = "0 таконов"
        }
        
        cell.descriptionLabel.text = service.descriptionField!
        cell.moreButton.tag = indexPath.section
        cell.moreButton.addTarget(self, action: #selector(self.moreClicked(_:)), for: .touchUpInside)
        cell.paymentButton.tag = indexPath.section
        cell.paymentButton.addTarget(self, action: #selector(self.makePayment(_:)), for: .touchUpInside)
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
    }
    
    
    // MARK: actions
    @objc func makePayment(_ sender: UIButton){
        let index = sender.tag
        let service = services[index]
        if self.isUse{
            ServiceVC.open(vc: self, id: service.id!, service: service, partner: self.partner!, isUse: true, userId: self.userId)
        }else{
             ServiceVC.open(vc: self, id: service.id!, service: service, partner: self.partner!, isUse: false, userId: 0)
        }
        
    }
    @objc func moreClicked(_ sender: UIButton){
        
        let index = sender.tag
        let service = services[index]
        let deleteAlert = UIAlertController(title: "Действия", message: "", preferredStyle: UIAlertController.Style.actionSheet)
        
        let generateQr = UIAlertAction(title: "Сгенерировать QR", style: .default) { (action: UIAlertAction) in
            ServiceVC.open(vc: self, id: service.id!, service: service, partner: self.partner!, isUse: false, userId: 0)
        }
        let sendFriend = UIAlertAction(title: "Передать другу", style: .default) { (action: UIAlertAction) in
            SendFriendVC.open(vc: self, id: service.id!, service: service, partner: self.partner!)
        }
        deleteAlert.addAction(generateQr)
        deleteAlert.addAction(sendFriend)
        if let e = service.paymentEnabled{
            if e == true{
                let purchase = UIAlertAction(title: "Пополнить счет", style: .default) { (action: UIAlertAction) in
                    BuyTakonsVC.open(vc: self, service: service, partner: self.partner!)
                }
                deleteAlert.addAction(purchase)
            }
        }
        
        
        let cancelAction = UIAlertAction(title: "Отмена", style: .cancel, handler: nil)

    

        deleteAlert.addAction(cancelAction)
//        self.present(deleteAlert, animated: true, completion: nil)
        
        if UIDevice.current.userInterfaceIdiom == .pad {
            deleteAlert.popoverPresentationController!.sourceView = self.view
            deleteAlert.popoverPresentationController!.sourceRect = CGRect(x: self.view.bounds.size.width / 2.0, y: self.view.bounds.size.height / 2.0, width: 1.0, height: 1.0)
            
            self.present(deleteAlert, animated: true, completion: nil)
        }else{
            self.present(deleteAlert, animated: true, completion: nil)

        }
        
        
    }
    
}
extension CompanyVC{
    
    func getOrganizationInfo(json: [String: AnyObject], completionHandler: @escaping (_ params: [Service]) -> ()) {
        
        let headers: HTTPHeaders = [
            "Authorization": "Bearer \(getToken())"
        ]
        
        Alamofire.request("\(url)getservices", method: .post, parameters: json, encoding: URLEncoding.default, headers: headers).responseObject{
            (response: DataResponse<OrganizationInfo>) in
            if response.response?.statusCode != nil {
                if (response.response?.statusCode)! == 200{
                    let info = response.result.value?.services
                    completionHandler(info!)
                }
                
            }
        }
        
    }
}
