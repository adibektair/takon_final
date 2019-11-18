//
//  OnlinePaymentCell.swift
//  TAKON V2
//
//  Created by root user on 10/8/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class OnlinePaymentCell: UITableViewCell, UITextFieldDelegate {

    var price = 0
    override func awakeFromNib() {
        super.awakeFromNib()
        self.amountTextField.delegate = self
    }
    @IBOutlet var textFieldView: UIView!{
        didSet{
            self.textFieldView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.7882352941, green: 0.8156862745, blue: 0.8549019608, alpha: 1))
        }
    }
    @IBOutlet var amountTextField: UITextField!{
        didSet{
            self.amountTextField.placeholder = "Введите количество таконов"
        }
    }
    @IBOutlet var amountLabel: UILabel!
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if textField.text != "" && textField.text != nil{
            self.amountLabel.text = "\(Int(textField.text!)! * self.price) тенге"
        }else{
            self.amountLabel.text = "0 тенге"
        }
    }

}
