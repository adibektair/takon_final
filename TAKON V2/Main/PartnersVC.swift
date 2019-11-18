//
//  PartnersVC.swift
//  TAKON V2
//
//  Created by root user on 10/22/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
class PartnersVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    var partners = [Organization]()
    
    override func viewWillDisappear(_ animated: Bool) {
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = true
        } else {
            // Fallback on earlier versions
        }
        self.tabBarController?.tabBar.isHidden = false
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Все организации"
        
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tabBarController?.tabBar.isHidden = true
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = false
        } else {
            // Fallback on earlier versions
        }
        self.tableView.rowHeight = 88
        self.tableView.register(UINib(nibName: "PartnerCell", bundle: nil), forCellReuseIdentifier: "PartnerCell")
        self.getData()
    
    }
    func getData(){
        self.getSubscribtions(completionHandler: { subs in
            self.partners = subs
            self.tableView.reloadData()
        })
    }
    
    // MARK: - Table view data source
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return 1
    }
    func numberOfSections(in tableView: UITableView) -> Int {
        return partners.count
    }
    
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let view = UIView()
        view.backgroundColor = .clear
        return view
    }
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 16
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "PartnerCell", for: indexPath) as! PartnerCell
        let partner = partners[indexPath.section]
        if let image = partner.imagePath{
            let url = URL(string: imageUrl + image.encodeUrl)
            cell.logoImageView.sd_setImage(with: url, completed: nil)
        }
        cell.nameLabel.text = partner.name!
        cell.cornerRadius(radius: 8, width: 0, color: .white)
        if let desc = partner.descriptionField{
            cell.descLabel.text = desc
        }else{
            cell.descLabel.text = ""
        }
        if partner.has! == 1{
            cell.makeRemovable()
        }else{
            cell.makeAddable()
        }
        cell.button.tag = indexPath.section
        cell.button.addTarget(self, action: #selector(self.edit(_:)), for: .touchUpInside)
        return cell
    }
    @objc func edit(_ sender: UIButton){
        let i = sender.tag
        let partner = partners[i]
        if partner.has! == 1{
            //remove
            let json = ["id" : partner.id!, "token" : getToken()] as [String: AnyObject]
            self.startLoading()
            self.removeSubs(params: json, completionHandler: { _ in
                self.singleVibration()
                self.stopLoading()
                self.getData()
            })
        }else{
            //add
            let json = ["partner_id" : partner.id!, "token" : getToken()] as [String : AnyObject]
            self.startLoading()
            self.addSubs(params: json, completionHandler: { _ in
                self.singleVibration()
                self.stopLoading()
                self.getData()
            })
            
        }
    }
    
    @IBOutlet var tableView: UITableView!
    

}
extension PartnersVC{
    func getSubscribtions(completionHandler: @escaping (_ params: [Organization]) -> ()) {
        Alamofire.request("\(url)get-partners", method: .post, parameters: ["token" : getToken()], encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<PartnersResponse>) in
            if let code = response.response?.statusCode{
                if code == 401{
                    let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
                    let newViewController = storyBoard.instantiateViewController(withIdentifier: "start")
                    self.present(newViewController, animated: false, completion: nil)
                }
                if let info = response.result.value?.partners{
                    completionHandler(info)
                }
            }
            
            
        }
        
    }
    
    func removeSubs(params: [String: AnyObject], completionHandler: @escaping (_ params: Bool) -> ()) {
        Alamofire.request("\(url)deletesubscription", method: .post, parameters: params, encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<StandartResponse>) in
            if let code = response.response?.statusCode{
               completionHandler(true)
            }
        }
    }
    func addSubs(params: [String: AnyObject], completionHandler: @escaping (_ params: Bool) -> ()) {
        Alamofire.request("\(url)addsubscription", method: .post, parameters: params, encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<StandartResponse>) in
            if let code = response.response?.statusCode{
                completionHandler(true)
            }
        }
    }
    static func open(vc: UIViewController){
        let viewController = PartnersVC(nibName: "PartnersVC", bundle: nil)
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
}
