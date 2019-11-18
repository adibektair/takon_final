//
//  CompanyTVC.swift
//  TAKON V2
//
//  Created by root user on 9/27/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class CompanyTVC: UITableViewCell {

    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var amountLabel: UILabel!
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var moreButton: UIButton!{
        didSet{
            self.moreButton.cornerRadius(radius: Int(self.moreButton.layer.bounds.size.height / 2), width: 0.5, color: #colorLiteral(red: 0.2549019754, green: 0.2745098174, blue: 0.3019607961, alpha: 1))
            self.moreButton.setImage(#imageLiteral(resourceName: "dots"), for: .normal)
        }
    }
    @IBOutlet var paymentButton: UIButton!{
        didSet{
            self.paymentButton.cornerRadius(radius: 8, width: 0, color: .white)
        }
    }
    
    
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.cornerRadius(radius: 16, width: 0.1, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        
        
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
