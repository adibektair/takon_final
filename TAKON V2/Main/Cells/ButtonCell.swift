//
//  ButtonCell.swift
//  TAKON V2
//
//  Created by root user on 10/1/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class ButtonCell: UITableViewCell {

    @IBOutlet var button: UIButton!{
        didSet{
            self.button.cornerRadius(radius: 8, width: 0, color: .white)
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.backgroundColor = .clear
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
