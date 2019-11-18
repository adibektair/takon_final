//
//  MainVC.swift
//  TAKON V2
//
//  Created by root user on 9/25/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
import SDWebImage
let imageUrl = "https://takon.org/public/avatars/"


class MainVC: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {

    var partners = [Partner]()
    
    override func viewWillAppear(_ animated: Bool) {
        self.tabBarController?.tabBar.isHidden = false
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = true
            
        } 
        self.getSubscribtions(completionHandler: { subs in
            self.partners = subs
            self.collectionView.reloadData()
        })
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Магазины"
        self.collectionView.delegate = self
        self.collectionView.dataSource = self
        self.collectionView!.register(UINib(nibName: "MainCell", bundle: nil), forCellWithReuseIdentifier: "MainCell")
    }
    
    
    @IBAction func openProfile(_ sender: Any) {
        ProfileVC.open(vc: self)
    }
    @IBOutlet var collectionView: UICollectionView!
 
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return partners.count
    }
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "MainCell", for: indexPath) as! MainCell
        let width = (UIScreen.main.bounds.size.width / 2) - 23
        let height = width * 1.17
        cell.bottomViewHeight.constant = height * 0.233
        let partner = partners[indexPath.row]
        cell.nameLabel.text = partner.name!
        if let des = partner.descriptionField{
            cell.descriptionLabel.text = des
        }
        if let image = partner.imagePath{
            let imagePath = URL(string: imageUrl + image.encodeUrl)
            cell.logoImageView!.sd_setImage(with: imagePath!, completed: nil)
        }
        if let amount = partner.amount{
            if Double(amount) > 0{
                cell.amountLabel.text =  "\(amount) таконов"
                cell.bottomView.backgroundColor = #colorLiteral(red: 0.8509803922, green: 0.9215686275, blue: 1, alpha: 1)
                cell.curveImageView.image = #imageLiteral(resourceName: "Screen Shot 2019-10-15 at 12.38.33 PM")
                cell.amountLabel.textColor = #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1)
            }else{
                cell.curveImageView.image = #imageLiteral(resourceName: "Screen Shot 2019-10-20 at 3.03.22 PM")
                cell.amountLabel.textColor = #colorLiteral(red: 0.4078431373, green: 0.4274509804, blue: 0.4862745098, alpha: 1)
                cell.amountLabel.text = "Нет таконов"
                cell.bottomView.backgroundColor = #colorLiteral(red: 0.8941176471, green: 0.9176470588, blue: 0.9490196078, alpha: 1)
            }
        }else{
            cell.amountLabel.textColor = #colorLiteral(red: 0.4078431373, green: 0.4274509804, blue: 0.4862745098, alpha: 1)
            cell.curveImageView.image = #imageLiteral(resourceName: "Screen Shot 2019-10-20 at 3.03.22 PM")
            cell.bottomView.backgroundColor = #colorLiteral(red: 0.8941176471, green: 0.9176470588, blue: 0.9490196078, alpha: 1)
            cell.amountLabel.text = "Нет таконов"
        }
        
        
        
        cell.cornerRadius(radius: 16, width: 0.2, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        
        return cell
    }
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize {
        let width = (UIScreen.main.bounds.size.width / 2) - 23
        let height = width * 1.17
        
        return CGSize(width: width, height: height)
        
    }
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        minimumInteritemSpacingForSectionAt section: Int) -> CGFloat {
        return 15.0
    }
    
    func collectionView(_ collectionView: UICollectionView, layout
        collectionViewLayout: UICollectionViewLayout,
                        minimumLineSpacingForSectionAt section: Int) -> CGFloat {
        return 15.0
    }
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let id = partners[indexPath.row].id!
        CompanyVC.open(vc: self, id: id, partner: partners[indexPath.row], isUse: false, userId: 0)
    }


    @IBAction func addPartner(_ sender: Any) {
        PartnersVC.open(vc: self)
    }
    
    
}
extension MainVC{
    
    func getSubscribtions(completionHandler: @escaping (_ params: [Partner]) -> ()) {
        Alamofire.request("\(url)getsubscriptions", method: .post, parameters: ["token" : getToken()], encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<MainPage>) in
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
    
}
//extension UIViewController {
//    func configureNavigationBar(largeTitleColor: UIColor, backgoundColor: UIColor, tintColor: UIColor, title: String, preferredLargeTitle: Bool) {
//        if #available(iOS 13.0, *) {
//            let navBarAppearance = UINavigationBarAppearance()
//            navBarAppearance.configureWithOpaqueBackground()
//            navBarAppearance.largeTitleTextAttributes = [.foregroundColor: largeTitleColor]
//            navBarAppearance.titleTextAttributes = [.foregroundColor: largeTitleColor]
//            navBarAppearance.backgroundColor = backgoundColor
//
//            navigationController?.navigationBar.standardAppearance = navBarAppearance
//            navigationController?.navigationBar.compactAppearance = navBarAppearance
//            navigationController?.navigationBar.scrollEdgeAppearance = navBarAppearance
//
//            navigationController?.navigationBar.prefersLargeTitles = preferredLargeTitle
//            navigationController?.navigationBar.isTranslucent = false
//            navigationController?.navigationBar.tintColor = tintColor
//            navigationItem.title = title
//
//        } else {
//            // Fallback on earlier versions
//            navigationController?.navigationBar.barTintColor = backgoundColor
//            navigationController?.navigationBar.tintColor = tintColor
//            navigationController?.navigationBar.isTranslucent = false
//            navigationItem.title = title
//        }
//    }}
