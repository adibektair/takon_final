//
//  QRCodeGeneratorVC.swift
//  TAKON V2
//
//  Created by root user on 10/2/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import Alamofire

class QRCodeGeneratorVC: UIViewController {

    // Mark: varaibles
    var amount: Int?
    var id: Int?
    
    // Mark: lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "QR код"
        let json = ["takon_id" : id!, "amount" : amount!, "token" : getToken()] as! Parameters
        self.QRGenerate(jsonObject: json, completionHandler: { qrstring in
            if qrstring == "error"{
                self.showAlert(title: "Ошибка", message: "Что-то пошло не так")
            }else{
                self.qrCodeImageView.image = self.generateQRCode(from: qrstring)
            }
            
        })
    }
    
    // Mark: outlets
    @IBOutlet var qrCodeImageView: UIImageView!
    @IBOutlet var tView: UIView!{
        didSet{
            self.tView.cornerRadius(radius: 8, width: 0, color: .white)
        }
    }
    static func open(vc: UIViewController, id: Int, amount : Int){
        let viewController = QRCodeGeneratorVC(nibName: "QRCodeGeneratorVC", bundle: nil)
        viewController.id = id
        viewController.amount = amount
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
    
}
extension QRCodeGeneratorVC{
    func generateQRCode(from string: String) -> UIImage? {
        let data = string.data(using: String.Encoding.ascii)
        
        if let filter = CIFilter(name: "CIQRCodeGenerator") {
            filter.setValue(data, forKey: "inputMessage")
            let transform = CGAffineTransform(scaleX: 10, y: 10)
            
            if let output = filter.outputImage?.transformed(by: transform) {
                return UIImage(ciImage: output)
            }
        }
        
        return nil
    }
    func QRGenerate(jsonObject: [String : Any], completionHandler: @escaping (String) -> ()){
        
        
        Alamofire.request(url + "qrgenerate", method: .post, parameters: jsonObject, encoding: URLEncoding.default, headers: nil)
            .responseJSON { response in
                print(response)
                
                if response.response?.statusCode != nil {
                    if (response.response?.statusCode)! < 310{
                        if let result = response.result.value{
                            let JSON = result as! NSDictionary
                            if let success = (JSON as! [String : AnyObject])["success"] as? Bool{
                                if(success == true){
                                    if let token = (JSON as! [String : AnyObject])["msg"]{
                                        
                                        completionHandler(token as! String)
                                    }
                                }else{
                                    completionHandler("error")
                                }
                            }
                            
                            
                        }
                    }
                }else{
                    completionHandler("error")
                }
        }
    }
}
