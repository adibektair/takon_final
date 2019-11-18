//
//  PartnerCell.swift
//  TAKON V2
//
//  Created by root user on 10/22/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class PartnerCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

    }
    
    @IBOutlet var logoImageView: UIImageView!{
        didSet{
            self.logoImageView.cornerRadius(radius: 8, width: 0.5, color: #colorLiteral(red: 0.483002305, green: 0.5043411851, blue: 0.5595493317, alpha: 1))
        }
    }
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var descLabel: UILabel!
    @IBOutlet var button: UIButton!{
        didSet{
            self.button.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
        }
    }
    
    func makeAddable(){
        self.button.setTitle("Добавить", for: .normal)
        self.button.setTitleColor(#colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1), for: .normal)
        self.button.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 0, green: 0.4784313725, blue: 1, alpha: 1))
    }
    
    func makeRemovable(){
        self.button.setTitle("Удалить", for: .normal)
        self.button.setTitleColor(#colorLiteral(red: 1, green: 0.231372549, blue: 0.1882352941, alpha: 1), for: .normal)
        self.button.cornerRadius(radius: 14, width: 1, color: #colorLiteral(red: 1, green: 0.231372549, blue: 0.1882352941, alpha: 1))
    }
    
    
    
}
