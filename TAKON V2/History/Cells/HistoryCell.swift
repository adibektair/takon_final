//
//  HistoryCell.swift
//  TAKON V2
//
//  Created by root user on 10/15/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class HistoryCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    @IBOutlet var logoImageView: UIImageView!{
        didSet{
            self.logoImageView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    @IBOutlet var senderLabel: UILabel!
    @IBOutlet var serviceLabel: UILabel!
    @IBOutlet var amountLabel: UILabel!
    @IBOutlet var dateLabel: UILabel!
    
}
