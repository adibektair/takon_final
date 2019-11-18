//
//  CardCell.swift
//  TAKON V2
//
//  Created by root user on 10/9/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class CardCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    @IBOutlet var buttonWidth: NSLayoutConstraint!
    @IBOutlet var cardNumberLabel: UILabel!
    @IBOutlet var selectButton: UIButton!{
        didSet{
            self.selectButton.cornerRadius(radius: 12, width: 0.5, color: #colorLiteral(red: 0.3056048751, green: 0.3208525479, blue: 0.3749331832, alpha: 1))
        }
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
