//
//  WalletOneVC.swift
//  TAKON V2
//
//  Created by root user on 12/4/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import WebKit

class WalletOneVC: UIViewController, WKNavigationDelegate {

    var url : String?
    override func viewDidLoad() {
        super.viewDidLoad()
        wkView.navigationDelegate = self
        wkView.load(URLRequest(url: URL(string: url!)!))
             
    }

    @IBOutlet var wkView: WKWebView!
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        if let url = webView.url{
            if url.absoluteString == "https://takon.org/api/wallet-success"{
                SuccessVC.open(vc: self, text: "Спасибо! Оплата прошла успешно! \n\nСпасибо за доверие!")
            }
        }
    }
    
    static func open(vc: UIViewController, url:String){
        let viewController = WalletOneVC(nibName: "WalletOneVC", bundle: nil)
        viewController.url = url
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }

}
