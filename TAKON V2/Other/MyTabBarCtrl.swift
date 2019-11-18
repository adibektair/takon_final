//
//  MyTabBarCtrl.swift
//  TAKON V2
//
//  Created by root user on 9/24/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import SwiftIcons

class MyTabBarCtrl: UITabBarController, UITabBarControllerDelegate {

    required init(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)!
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.delegate = self
        self.setupMiddleButton()
    }
    
    // TabBarButton – Setup Middle Button
    func setupMiddleButton() {
        
        
        let middleBtn = UIButton(frame: CGRect(x: (self.view.bounds.width / 2)-30, y: -30, width: 60, height: 60))
        
        
        middleBtn.setIcon(icon: .fontAwesomeSolid(.qrcode), iconSize: 30.0, color: UIColor.white, backgroundColor: #colorLiteral(red: 0.001522830636, green: 0.5363063135, blue: 0.002362810386, alpha: 1), forState: .normal)
//        middleBtn.backgroundColor = #colorLiteral(red: 0.2039215686, green: 0.7803921569, blue: 0.3490196078, alpha: 1)
//        middleBtn.setImage(#imageLiteral(resourceName: "qr-code-icon-png-1.jpg"), for: .normal)
//        middleBtn.imageView?.frame = CGRect(x: 5, y: 5, width: 10, height: 15)
//        middleBtn.imageView?.contentMode = .scaleAspectFit
        middleBtn.layer.cornerRadius = middleBtn.frame.size.height / 2
        middleBtn.imageEdgeInsets = UIEdgeInsets(top: 10, left: 10, bottom: 10, right: 10)
        middleBtn.isUserInteractionEnabled = true
//        middleBtn.applyGradient(colors: colorBlueDark.cgColor,colorBlueLight.cgColor])
        
        //add to the tabbar and add click event
        self.tabBar.addSubview(middleBtn)
        middleBtn.addTarget(self, action: #selector(self.menuButtonAction), for: .touchUpInside)
        
        self.view.layoutIfNeeded()
    }
    
    // Menu Button Touch Action
    @objc func menuButtonAction(sender: UIButton) {
//        self.selectedIndex = 1   //to select the middle tab. use "1" if you have only 3 tabs.
        let scanner = ScannerVC(nibName: "ScannerVC", bundle: nil)
        let navigationController = UINavigationController()
        navigationController.viewControllers = [scanner]
        self.present(navigationController, animated: true, completion: nil)
    }
    
}



