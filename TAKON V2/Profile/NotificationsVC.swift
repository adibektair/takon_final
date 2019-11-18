//
//  NotificationsVC.swift
//  TAKON V2
//
//  Created by root user on 10/16/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class NotificationsVC: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Уведомления"
        // Do any additional setup after loading the view.
    }

    @IBOutlet var `switch`: UISwitch!
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    static func open(vc: UIViewController){
        let viewController = NotificationsVC(nibName: "NotificationsVC", bundle: nil)
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
}
