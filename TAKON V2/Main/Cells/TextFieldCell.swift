//
//  TextFieldCell.swift
//  TAKON V2
//
//  Created by root user on 10/10/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit

class TextFieldCell: UITableViewCell {

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
   
    @IBOutlet var label: UILabel!
    @IBOutlet var textField: UITextField!
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
