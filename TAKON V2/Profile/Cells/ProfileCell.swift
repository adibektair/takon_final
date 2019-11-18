//
//  ProfileCell.swift
//  TAKON V2
//
//  Created by root user on 10/16/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class ProfileCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    @IBOutlet var iconImageView: UIImageView!{
        didSet{
            self.iconImageView.cornerRadius(radius: 8, width: 0, color: .white)
        }
    }
    @IBOutlet var innerTextLabel: UILabel!
    
}
