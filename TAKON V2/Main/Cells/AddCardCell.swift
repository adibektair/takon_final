//
//  AddCardCell.swift
//  TAKON V2
//
//  Created by root user on 10/9/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class AddCardCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
    
    @IBOutlet var addCardButton: UIButton!{
        didSet{
            self.addCardButton.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
        }
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

    }
    
}
