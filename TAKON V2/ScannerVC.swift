//
//  ScannerVC.swift
//  TAKON V2
//
//  Created by root user on 9/30/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import AVFoundation
import Alamofire

class ScannerVC: UIViewController {

    // MARK: variables
    var response : Response?
    var scanned = false
    // Mark: Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Оплата"
    }
    override func viewDidLayoutSubviews() {
        let reader = QRCodeReader()
        do {
            try  reader.startScanning(view: self.scannerView) {
                decodedQrCode in
                
                guard let decodedQrCode = decodedQrCode else {
                    return
                }
                
                DispatchQueue.main.async {
                    UIPasteboard.general.string = decodedQrCode
                    print(decodedQrCode)
                    let code : String = decodedQrCode
                    let json = [
                        "qrstring" : code,
                        "token" : self.getToken()
                        ] as [String: String]
                    if self.scanned == false{
                        reader.stopScanning()
                        self.scanned = true
                        self.startLoading()
                        self.scan(jsonObject: json, completionHandler: { response in
                            self.stopLoading()
                            self.response = response
                            if (self.response?.success!)!{
                                
                                if let _ = response.partner_id{
                                    
                                    CompanyVC.open(vc: self, id: (self.response?.partner_id!)!, partner: (self.response?.partner!)!, isUse: true, userId: response.user_id!)
                                    
                                }
                                else{
                                    
                                    let alert = UIAlertController(title: "Успешно", message: "", preferredStyle: UIAlertController.Style.alert)
                                    alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: { (log) in
                                        self.dismiss(animated: true, completion: nil)
                                    }))
                                    self.present(alert, animated: true, completion: nil)
                                    
                                }
                            }
                            else{
                                
                                self.showAlert(title: "Внимание", message: "Произошла непредвиденная ошибка, попробуйте позже")
                                
                            }
                        })
                    }
                    
                    
                }
                
                reader.stopScanning()
            }
        } catch {
            print("\(error.localizedDescription)")
            reader.stopScanning()
        }
    }

    // Mark: Outlets
    @IBOutlet var scannerView: UIView!{
        didSet{
            self.scannerView.cornerRadius(radius: 1, width: 0.6, color: #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1))
        }
    }
    @IBOutlet var tView: UIView!{
        didSet{
            self.tView.cornerRadius(radius: 8, width: 0, color: .black)
        }
    }
    

    @IBAction func closeButtonPressed(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
    }
    static func open(vc: UIViewController){
        let viewController = ScannerVC(nibName: "ScannerVC", bundle: nil)
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }

}
extension ScannerVC{
    func scan(jsonObject: [String : Any], completionHandler: @escaping (_ params: Response) -> ()) {
        

        Alamofire.request("\(url)qr_scan_for_presenting", method: .post, parameters: jsonObject, encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<Response>) in
            if let responseCode = response.response?.statusCode{
                if responseCode == 200{
                    let info = response.result.value
                    completionHandler(info!)
                }else{
                    self.showAlert(title: "Ошибка", message: "Недействительный QR код")
                }
            }
        }
        
    }
}
