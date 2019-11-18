//
//  MainCell.swift
//  TAKON V2
//
//  Created by root user on 9/24/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import SDWebImage

class MainCell: UICollectionViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        self.bottomViewHeight.constant = self.frame.height * 0.23333

    }
    
    @IBOutlet var bottomViewHeight: NSLayoutConstraint!
    @IBOutlet var curveImageView: UIImageView!
    @IBOutlet var logoImageView: UIImageView!{
        didSet{
            self.logoImageView.cornerRadius(radius: 8, width: 0.3, color: #colorLiteral(red: 0.2549019754, green: 0.2745098174, blue: 0.3019607961, alpha: 1))
        }
    }
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var amountLabel: UILabel!
    @IBOutlet var bottomView: UIView!{
        didSet{
            
        }
    }
    
}
