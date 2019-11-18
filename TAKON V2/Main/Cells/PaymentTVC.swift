//
//  PaymentTVC.swift
//  TAKON V2
//
//  Created by root user on 9/30/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class PaymentTVC: UITableViewCell {

    
    
    @IBOutlet var logoImageView: UIImageView!{
        didSet{
            self.logoImageView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    @IBOutlet var serviceNameLabel: UILabel!
    @IBOutlet var takonAmountLabel: UILabel!
    @IBOutlet var changeButton: UIButton!{
        didSet{
            self.changeButton.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
        }
    }
    @IBOutlet var textView: UIView!
        {
        didSet{
            self.textView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    @IBOutlet var amountTextField: UITextField!
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
enum PaymentFields {
    case name
    case amount
    case phone
    case phoneNumber
    case button
}
