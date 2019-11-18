//
//  HistoryVC.swift
//  TAKON V2
//
//  Created by root user on 10/15/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire
import SDWebImage

class HistoryVC: UIViewController, UITableViewDelegate, UITableViewDataSource {

    var transactions = [History]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.allowsSelection = false
        self.title = "Операции"
        if #available(iOS 11.0, *) {
            self.navigationController?.navigationBar.prefersLargeTitles = true
        } else {
            // Fallback on earlier versions
        }
        self.tableView.register(UINib(nibName: "HistoryCell", bundle: nil), forCellReuseIdentifier: "HistoryCell")
        self.tableView.register(UINib(nibName: "HeaderTVC", bundle: nil), forCellReuseIdentifier: "HeaderTVC")
    }
    override func viewWillAppear(_ animated: Bool) {
        self.startLoading()
        self.getHistory(completionHandler: { history in
            self.stopLoading()
            self.transactions = history
            self.transactions.reverse()
            self.tableView.reloadData()
        })
    }
    
    @IBOutlet var tableView: UITableView!
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 76.0
    }
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 35.0
    }
    func numberOfSections(in tableView: UITableView) -> Int {
        return self.transactions.count
    }
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let cell = tableView.dequeueReusableCell(withIdentifier: "HeaderTVC") as! HeaderTVC
        
        cell.innerTextLabel.text = self.getHeaderDate(date: transactions[section].date!)
        cell.backgroundColor = #colorLiteral(red: 0.8941176471, green: 0.9176470588, blue: 0.9490196078, alpha: 1)
        return cell
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.transactions[0].transactions!.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryCell", for: indexPath) as! HistoryCell
        cell.senderLabel.text = self.transactions[indexPath.section].transactions?[indexPath.row].contragent!
        cell.serviceLabel.text = self.transactions[indexPath.section].transactions?[indexPath.row].service!
        
        if (self.transactions[indexPath.section].transactions?[indexPath.row].amount!)! > 0{
            cell.amountLabel.textColor = #colorLiteral(red: 0.4666666687, green: 0.7647058964, blue: 0.2666666806, alpha: 1)
        }else{
            cell.amountLabel.textColor = #colorLiteral(red: 0.9254902005, green: 0.2352941185, blue: 0.1019607857, alpha: 1)
        }
        if let amount = self.transactions[indexPath.section].transactions?[indexPath.row].amount{
            cell.amountLabel.text = "\(amount)"
        }
        
        if let date = self.transactions[indexPath.section].transactions?[indexPath.row].date{
            cell.dateLabel.text = self.getCellDate(date: "\(date)")
        }
        
        if let image = self.transactions[indexPath.section].transactions?[indexPath.row].imagePath{
            let url = URL(string: imageUrl + image.encodeUrl)
            cell.logoImageView.sd_setImage(with: url, completed: nil)
        }
        
        return cell
    }

    var russianMonthes = ["January" : "Январь",
    "February" : "Февраль",
    "March" : "Март",
    "April" : "Апрель",
    "May" : "Май",
    "June" : "Июнь",
    "July" : "Июль",
    "August" : "Август",
    "September" : "Сентябрь",
    "October" : "Октябрь",
    "November" : "Ноябрь",
    "December" : "Декабрь"]
    
    func getHeaderDate(date: String) -> String{
        let dateString = date
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd"
        guard let date = formatter.date(from: dateString) else {
            return ""
        }
        
        formatter.dateFormat = "yyyy"
        let year = formatter.string(from: date)
        formatter.dateFormat = "LLLL"
        let month = formatter.string(from: date)
        formatter.dateFormat = "dd"
        let day = formatter.string(from: date)
        
        
        return russianMonthes[month]! + ", " + day
    }
    
    func getCellDate(date: String) -> String{
        let dateString = date
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        guard let date = formatter.date(from: dateString) else {
            return ""
        }
        
        formatter.dateFormat = "HH"
        let hour = formatter.string(from: date)
        formatter.dateFormat = "mm"
        let min = formatter.string(from: date)
     
        
        return hour + ":" + min
    }
}
extension HistoryVC{
    func getHistory(completionHandler: @escaping (_ params: [History]) -> ()) {
        Alamofire.request("\(url)transaction-history", method: .post, parameters: ["token" : getToken()], encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<HistoryResponse>) in
            if let code = response.response?.statusCode{
                if code == 401{
                    let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
                    let newViewController = storyBoard.instantiateViewController(withIdentifier: "start")
                    self.present(newViewController, animated: false, completion: nil)
                }
                if let info = response.result.value?.history{
                    completionHandler(info)
                }
            }
            
            
        }
        
    }
}

