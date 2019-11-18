//
//  PhoneNumberTVC.swift
//  TAKON V2
//
//  Created by root user on 9/30/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class PhoneNumberTVC: UITableViewCell {

    
    @IBOutlet var textView: UIView!{
        didSet{
            self.textView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.3056048751, green: 0.3208525479, blue: 0.3749331832, alpha: 1))
        }
    }
    
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var phoneNumberTextField: UITextField!
    @IBOutlet var getFromContactsButton: UIButton!{
        didSet{
            self.getFromContactsButton.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
