import UIKit
import Foundation

let dark = UIView()
let small = UIView()
var indicator = UIActivityIndicatorView()

extension UIViewController {
    
    func saveObject(object: NSObject, key: String){
        let encodedData = NSKeyedArchiver.archivedData(withRootObject: object)
        let userDefaults = UserDefaults.standard
        userDefaults.set(encodedData, forKey: key)
    }
    func getSavedObject(forKey: String) -> NSObject{
        if let decoded  = UserDefaults.standard.object(forKey: forKey) as? Data{
            let object = NSKeyedUnarchiver.unarchiveObject(with: decoded)
            return object as! NSObject
        }
        return NSObject()
    }
    
    
    func getToken() -> String{
        if let token = UserDefaults.standard.string(forKey: "token"){
            return token
        }else{
            return "";
        }
        
    }
    
    func hideKeyboardWhenTappedAround() {
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(UIViewController.dismissKeyboard))
        tap.cancelsTouchesInView = false
        view.addGestureRecognizer(tap)
    }
    
    @objc func dismissKeyboard() {
        view.endEditing(true)
    }
    
    func format(phoneNumber: String, shouldRemoveLastDigit: Bool = false) -> String {
        guard !phoneNumber.isEmpty else { return "" }
        guard let regex = try? NSRegularExpression(pattern: "[\\s-\\(\\)]", options: .caseInsensitive) else { return "" }
        let r = NSString(string: phoneNumber).range(of: phoneNumber)
        var number = regex.stringByReplacingMatches(in: phoneNumber, options: .init(rawValue: 0), range: r, withTemplate: "")
        
        if number.count > 10 {
            let tenthDigitIndex = number.index(number.startIndex, offsetBy: 10)
            number = String(number[number.startIndex..<tenthDigitIndex])
        }
        
        if shouldRemoveLastDigit {
            let end = number.index(number.startIndex, offsetBy: number.count-1)
            number = String(number[number.startIndex..<end])
        }
        
        if number.count < 7 {
            let end = number.index(number.startIndex, offsetBy: number.count)
            let range = number.startIndex..<end
            number = number.replacingOccurrences(of: "(\\d{3})(\\d+)", with: "($1) $2", options: .regularExpression, range: range)
            
        } else {
            let end = number.index(number.startIndex, offsetBy: number.count)
            let range = number.startIndex..<end
            number = number.replacingOccurrences(of: "(\\d{3})(\\d{3})(\\d+)", with: "($1) $2-$3", options: .regularExpression, range: range)
        }
        
        return number
    }
    
    
    func showAlert(title: String, message: String){
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertController.Style.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
    
    func successVibration(){
        let impact = UIImpactFeedbackGenerator()
        let selection = UISelectionFeedbackGenerator()
        let notification = UINotificationFeedbackGenerator()
        
        notification.notificationOccurred(.success)
        
    }
    func errorVibration(){
        let impact = UIImpactFeedbackGenerator()
        let selection = UISelectionFeedbackGenerator()
        let notification = UINotificationFeedbackGenerator()
        
        notification.notificationOccurred(.error)
    }
    func singleVibration(){
        let impact = UIImpactFeedbackGenerator()
        impact.impactOccurred()
    }
    func startLoading(){
        
        let w = UIScreen.main.bounds.size.width
        let h = UIScreen.main.bounds.size.height
        dark.frame = CGRect(x: 0, y: 0, width: w, height: h)
        dark.backgroundColor = UIColor.gray.withAlphaComponent(0.3)
        small.frame.size = CGSize(width: w * 0.25, height: w * 0.25)
        small.backgroundColor = UIColor.white
        small.layer.cornerRadius = 15
        small.center = dark.center
        indicator.style = .gray
        indicator.color = UIColor.black
        indicator = UIActivityIndicatorView(style: UIActivityIndicatorView.Style.gray)
        indicator.frame = CGRect(x: 0, y: 0, width: 50, height: 50)
        let transform: CGAffineTransform = CGAffineTransform(scaleX: 1.5, y: 1.5)
        indicator.transform = transform
        indicator.center = dark.center
        
        
        
        
        
        //        indicator.center = small.center
        
        //        small.addSubview(indicator)
        dark.addSubview(small)
        dark.addSubview(indicator)
        view.addSubview(dark)
        indicator.startAnimating()
    }
    func stopLoading(){
        dark.removeFromSuperview()
    }
    

    
}



extension String{
    var encodeUrl : String
    {
        return self.addingPercentEncoding(withAllowedCharacters: NSCharacterSet.urlQueryAllowed)!
    }
    var decodeUrl : String
    {
        return self.removingPercentEncoding!
    }
}
