//
//  UIViewExtension.swift
//  TAKON V2
//
//  Created by root user on 9/23/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import Foundation
import UIKit

extension UIView{
    func cornerRadius(radius: Int, width: CGFloat, color: UIColor){
        self.layer.masksToBounds = true
        self.layer.cornerRadius = CGFloat(radius)
        self.layer.borderWidth = width
        self.layer.borderColor = color.cgColor
    }
    
    func make(path: UIBezierPath, point: CGPoint, amplitude: CGFloat){
        let middle = (point.x + path.currentPoint.x) / 2
        path.addQuadCurve(to: point, controlPoint: CGPoint(x: middle, y: point.y + amplitude))
    }
   
}
