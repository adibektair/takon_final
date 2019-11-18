//
//  SuccessVC.swift
//  TAKON V2
//
//  Created by root user on 10/21/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class SuccessVC: UIViewController {

    var text : String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.textLabel.text = self.text!
        self.title = "Успешно"
    }

    @IBOutlet var textLabel: UILabel!
    @IBOutlet var blueButton: UIButton!{
        didSet{
            self.blueButton.cornerRadius(radius: 8, width: 0, color: .white)
        }
    }
    

    @IBAction func buttonPressed(_ sender: Any) {
        self.navigationController?.popToRootViewController(animated: true)
    }
    
    static func open(vc: UIViewController, text: String){
        let viewController = SuccessVC(nibName: "SuccessVC", bundle: nil)
        viewController.text = text
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
}
