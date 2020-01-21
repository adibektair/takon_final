//
//  Objects.swift
//  TAKON V2
//
//  Created by root user on 9/25/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import Foundation
import UIKit
import ObjectMapper
import Alamofire
import  AlamofireObjectMapper




class StandartResponse : NSObject, NSCoding, Mappable{
    
    var message : String?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return StandartResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        message <- map["message"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        message = aDecoder.decodeObject(forKey: "message") as? String
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if message != nil{
            aCoder.encode(message, forKey: "message")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}


class WalletOneResponse : NSObject, NSCoding, Mappable{
    
    var url : String?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return WalletOneResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        url <- map["url"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        url = aDecoder.decodeObject(forKey: "url") as? String
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if url != nil{
            aCoder.encode(url, forKey: "url")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}

class MainPage : NSObject, NSCoding, Mappable{
    
    var partners : [Partner]?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return MainPage()
    }
    private override init(){}
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        partners <- map["partners"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        partners = aDecoder.decodeObject(forKey: "partners") as? [Partner]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if partners != nil{
            
            aCoder.encode(partners, forKey: "partners")
        }
        if success != nil{
            aCoder.encodeConditionalObject(success, forKey: "success")
        }
        
    }
    
}




class Partner : NSObject, NSCoding, Mappable{
    
    var address : String?
    var amount : Double?
    var createdAt : String?
    var descriptionField : String?
    var id : Int?
    var imagePath : String?
    var name : String?
    var phone : String?
    var updatedAt : String?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return Partner()
    }
    required init?(map: Map){}
     override init(){}
    
    func mapping(map: Map)
    {
        address <- map["address"]
        amount <- map["amount"]
        createdAt <- map["created_at"]
        descriptionField <- map["description"]
        id <- map["id"]
        imagePath <- map["image_path"]
        name <- map["name"]
        phone <- map["phone"]
        updatedAt <- map["updated_at"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        address = aDecoder.decodeObject(forKey: "address") as? String
        amount = aDecoder.decodeObject(forKey: "amount") as? Double
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        descriptionField = aDecoder.decodeObject(forKey: "description") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        imagePath = aDecoder.decodeObject(forKey: "image_path") as? String
        name = aDecoder.decodeObject(forKey: "name") as? String
        phone = aDecoder.decodeObject(forKey: "phone") as? String
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if address != nil{
            aCoder.encode(address, forKey: "address")
        }
        if amount != nil{
            aCoder.encode(amount, forKey: "amount")
        }
        if createdAt != nil{
            aCoder.encode(createdAt, forKey: "created_at")
        }
        if descriptionField != nil{
            aCoder.encode(descriptionField, forKey: "description")
        }
        if id != nil{
            aCoder.encode(id, forKey: "id")
        }
        if imagePath != nil{
            aCoder.encode(imagePath, forKey: "image_path")
        }
        if name != nil{
            aCoder.encode(name, forKey: "name")
        }
        if phone != nil{
            aCoder.encode(phone, forKey: "phone")
        }
        if updatedAt != nil{
            aCoder.encode(updatedAt, forKey: "updated_at")
        }
        
    }
    
}

class OrganizationInfo : NSObject, NSCoding, Mappable{
    
    var services : [Service]?
    var success : Bool?
    
    class func newInstance(map: Map) -> Mappable?{
        return OrganizationInfo()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        services <- map["services"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        services = aDecoder.decodeObject(forKey: "services") as? [Service]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if services != nil{
            aCoder.encode(services, forKey: "services")
            aCoder.encode(success, forKey: "success")
            
        }
        
    }
    
}


class Service : NSObject, NSCoding, Mappable{
    
    var createdAt : String?
    var company : String?
    var deadline : String?
    var descriptionField : String?
    var paymentEnabled : Bool?
    var paymentPrice : Int?
    
    var id : Int?
    var name : String?
    var price : Int?
    var usersAmount : Double?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return Service()
    }
    required init?(map: Map){}
    override init(){}
    
    func mapping(map: Map)
    {
        company <- map["company"]
        deadline <- map["deadline"]
        paymentPrice <- map["payment_price"]
        
        createdAt <- map["created_at"]
        id <- map["id"]
        name <- map["name"]
        price <- map["price"]
        usersAmount <- map["usersAmount"]
        descriptionField <- map["description"]
        paymentEnabled <- map["payment_enabled"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        company = aDecoder.decodeObject(forKey: "company") as? String
        deadline = aDecoder.decodeObject(forKey: "deadline") as? String
        paymentEnabled = aDecoder.decodeObject(forKey: "payment_enabled") as? Bool
        paymentPrice = aDecoder.decodeObject(forKey: "payment_price") as? Int
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        name = aDecoder.decodeObject(forKey: "name") as? String
        price = aDecoder.decodeObject(forKey: "price") as? Int
        usersAmount = aDecoder.decodeObject(forKey: "usersAmount") as? Double
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        
        if createdAt != nil{
            aCoder.encode(createdAt, forKey: "created_at")
        }
        if id != nil{
            aCoder.encode(id, forKey: "id")
        }
        if name != nil{
            aCoder.encode(name, forKey: "name")
        }
        if price != nil{
            aCoder.encode(price, forKey: "price")
        }
        if usersAmount != nil{
            aCoder.encode(usersAmount, forKey: "usersAmount")
        }
        if deadline != nil{
            aCoder.encode(deadline, forKey: "deadline")
        }
        if company != nil{
            aCoder.encode(company, forKey: "company")
        }
        if paymentEnabled != nil{
            aCoder.encode(company, forKey: "payment_enabled")
        }
        if paymentPrice != nil{
            aCoder.encode(company, forKey: "payment_price")
        }
        
    }
    
}

class MainTakons : NSObject, NSCoding, Mappable{
    
    var takons : [UsersServices]?
    var success : Bool?
    
    class func newInstance(map: Map) -> Mappable?{
        return MainTakons()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        takons <- map["services"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        takons = aDecoder.decodeObject(forKey: "services") as? [UsersServices]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if takons != nil{
            aCoder.encode(takons, forKey: "services")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}

class UsersServices : NSObject, NSCoding, Mappable{
    
    var amount : AnyObject?
    var company : String?
    var createdAt : String?
    var deadline : String?
    var id : Int?
    var isActive : AnyObject?
    var name : String?
    var partnerId : Int?
    var price : Int?
    var status : Int?
    var updatedAt : String?
    var usersAmount : Double?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return UsersServices()
    }
    private override init(){}
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        amount <- map["amount"]
        company <- map["company"]
        createdAt <- map["created_at"]
        deadline <- map["deadline"]
        id <- map["id"]
        isActive <- map["is_active"]
        name <- map["name"]
        partnerId <- map["partner_id"]
        price <- map["price"]
        status <- map["status"]
        updatedAt <- map["updated_at"]
        usersAmount <- map["usersAmount"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        amount = aDecoder.decodeObject(forKey: "amount") as? AnyObject
        company = aDecoder.decodeObject(forKey: "company") as? String
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        deadline = aDecoder.decodeObject(forKey: "deadline") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        isActive = aDecoder.decodeObject(forKey: "is_active") as? AnyObject
        name = aDecoder.decodeObject(forKey: "name") as? String
        partnerId = aDecoder.decodeObject(forKey: "partner_id") as? Int
        price = aDecoder.decodeObject(forKey: "price") as? Int
        status = aDecoder.decodeObject(forKey: "status") as? Int
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        usersAmount = aDecoder.decodeObject(forKey: "usersAmount") as? Double
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if amount != nil{
            aCoder.encodeConditionalObject(amount, forKey: "amount")
        }
        if company != nil{
            aCoder.encodeConditionalObject(company, forKey: "company")
        }
        if createdAt != nil{
            aCoder.encodeConditionalObject(createdAt, forKey: "created_at")
        }
        if deadline != nil{
            aCoder.encodeConditionalObject(deadline, forKey: "deadline")
        }
        if id != nil{
            aCoder.encodeConditionalObject(id, forKey: "id")
        }
        if isActive != nil{
            aCoder.encodeConditionalObject(isActive, forKey: "is_active")
        }
        if name != nil{
            aCoder.encodeConditionalObject(name, forKey: "name")
        }
        if partnerId != nil{
            aCoder.encodeConditionalObject(partnerId, forKey: "partner_id")
        }
        if price != nil{
            aCoder.encodeConditionalObject(price, forKey: "price")
        }
        if status != nil{
            aCoder.encodeConditionalObject(status, forKey: "status")
        }
        if updatedAt != nil{
            aCoder.encodeConditionalObject(updatedAt, forKey: "updated_at")
        }
        if usersAmount != nil{
            aCoder.encodeConditionalObject(usersAmount, forKey: "usersAmount")
        }
        
    }
    
}

class Response : NSObject, Mappable{
    
    var success : Bool?
    var partner_id: Int?
    var partner_name: String?
    var user_id: Int?
    var user: MobileUser?
    var partner: Partner?
    
    class func newInstance(map: Map) -> Mappable?{
        return Response()
    }
    private override init(){}
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        user <- map["user"]
        partner_id <- map["partner_id"]
        partner_name <- map["partner_name"]
        user_id <- map["user_id"]
        partner <- map["partner"]
        success <- map["success"]
        
    }
}

class MobileUser : NSObject, NSCoding, Mappable{
    
    var createdAt : String?
    var id : Int?
    var name : String?
    var phone : String?
    var platform : Int?
    var pushId : String?
    var token : String?
    var updatedAt : String?
        var lastName : String?
        var firstName : String?
        var iin : String?
    
    class func newInstance(map: Map) -> Mappable?{
        return MobileUser()
    }
    private override init(){}
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        createdAt <- map["created_at"]
        id <- map["id"]
        name <- map["name"]
        phone <- map["phone"]
        platform <- map["platform"]
        pushId <- map["push_id"]
        token <- map["token"]
        updatedAt <- map["updated_at"]
        lastName <- map["last_name"]
        firstName <- map["first_name"]
        iin <- map["iin"]

    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        name = aDecoder.decodeObject(forKey: "name") as? String
        phone = aDecoder.decodeObject(forKey: "phone") as? String
        platform = aDecoder.decodeObject(forKey: "platform") as? Int
        pushId = aDecoder.decodeObject(forKey: "push_id") as? String
        token = aDecoder.decodeObject(forKey: "token") as? String
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        lastName = aDecoder.decodeObject(forKey: "last_name") as? String
        firstName = aDecoder.decodeObject(forKey: "first_name") as? String
        iin = aDecoder.decodeObject(forKey: "iin") as? String
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if createdAt != nil{
            aCoder.encodeConditionalObject(createdAt, forKey: "created_at")
        }
        if id != nil{
            aCoder.encodeConditionalObject(id, forKey: "id")
        }
        if name != nil{
            aCoder.encodeConditionalObject(name, forKey: "name")
        }
        if phone != nil{
            aCoder.encodeConditionalObject(phone, forKey: "phone")
        }
        if platform != nil{
            aCoder.encodeConditionalObject(platform, forKey: "platform")
        }
        if pushId != nil{
            aCoder.encodeConditionalObject(pushId, forKey: "push_id")
        }
        if token != nil{
            aCoder.encodeConditionalObject(token, forKey: "token")
        }
        if updatedAt != nil{
            aCoder.encodeConditionalObject(updatedAt, forKey: "updated_at")
        }
        
    }
    
}



class CardsObj : Mappable{
    
    var cards : [Card1]?
    
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        cards <- map["cards"]
        
    }
}

class Card1 : Mappable {
    
    var cardLastFour : String?
    var id : Int?
    
    
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        cardLastFour <- map["CardLastFour"]
        id <- map["id"]
    }
}




class HistoryResponse : NSObject, NSCoding, Mappable{
    
    var history : [History]?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return HistoryResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        history <- map["history"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        history = aDecoder.decodeObject(forKey: "history") as? [History]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if history != nil{
            aCoder.encode(history, forKey: "history")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}


class History : NSObject, NSCoding, Mappable{
    
    var date : String?
    var transactions : [Transaction]?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return History()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        date <- map["date"]
        transactions <- map["transactions"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        date = aDecoder.decodeObject(forKey: "date") as? String
        transactions = aDecoder.decodeObject(forKey: "transactions") as? [Transaction]
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if date != nil{
            aCoder.encode(date, forKey: "date")
        }
        if transactions != nil{
            aCoder.encode(transactions, forKey: "transactions")
        }
        
    }
    
}


class Transaction : NSObject, NSCoding, Mappable{
    
    var amount : Double?
    var company : String?
    var contragent : String?
    var date : String?
    var imagePath : String?
    var service : String?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return Transaction()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        amount <- map["amount"]
        company <- map["company"]
        contragent <- map["contragent"]
        date <- map["date"]
        imagePath <- map["image_path"]
        service <- map["service"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        amount = aDecoder.decodeObject(forKey: "amount") as? Double
        company = aDecoder.decodeObject(forKey: "company") as? String
        contragent = aDecoder.decodeObject(forKey: "contragent") as? String
        date = aDecoder.decodeObject(forKey: "date") as? String
        imagePath = aDecoder.decodeObject(forKey: "image_path") as? String
        service = aDecoder.decodeObject(forKey: "service") as? String
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if amount != nil{
            aCoder.encode(amount, forKey: "amount")
        }
        if company != nil{
            aCoder.encode(company, forKey: "company")
        }
        if contragent != nil{
            aCoder.encode(contragent, forKey: "contragent")
        }
        if date != nil{
            aCoder.encode(date, forKey: "date")
        }
        if imagePath != nil{
            aCoder.encode(imagePath, forKey: "image_path")
        }
        if service != nil{
            aCoder.encode(service, forKey: "service")
        }
        
    }
    
}




class UserResponse : NSObject, NSCoding, Mappable{
    
    var success : Bool?
    var user : User?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return UserResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        success <- map["success"]
        user <- map["user"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        user = aDecoder.decodeObject(forKey: "user") as? User
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        if user != nil{
            aCoder.encode(user, forKey: "user")
        }
        
    }
    
}


class PartnersResponse : NSObject, NSCoding, Mappable{
    
    var partners : [Organization]?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return PartnersResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        partners <- map["partners"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        partners = aDecoder.decodeObject(forKey: "partners") as? [Organization]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if partners != nil{
            aCoder.encode(partners, forKey: "partners")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}

class Organization : NSObject, NSCoding, Mappable{
    
    var address : String?
    var createdAt : String?
    var descriptionField : String?
    var has : Int?
    var id : Int?
    var imagePath : String?
    var name : String?
    var phone : String?
    var updatedAt : String?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return Organization()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        address <- map["address"]
        createdAt <- map["created_at"]
        descriptionField <- map["description"]
        has <- map["has"]
        id <- map["id"]
        imagePath <- map["image_path"]
        name <- map["name"]
        phone <- map["phone"]
        updatedAt <- map["updated_at"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        address = aDecoder.decodeObject(forKey: "address") as? String
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        descriptionField = aDecoder.decodeObject(forKey: "description") as? String
        has = aDecoder.decodeObject(forKey: "has") as? Int
        id = aDecoder.decodeObject(forKey: "id") as? Int
        imagePath = aDecoder.decodeObject(forKey: "image_path") as? String
        name = aDecoder.decodeObject(forKey: "name") as? String
        phone = aDecoder.decodeObject(forKey: "phone") as? String
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if address != nil{
            aCoder.encode(address, forKey: "address")
        }
        if createdAt != nil{
            aCoder.encode(createdAt, forKey: "created_at")
        }
        if descriptionField != nil{
            aCoder.encode(descriptionField, forKey: "description")
        }
        if has != nil{
            aCoder.encode(has, forKey: "has")
        }
        if id != nil{
            aCoder.encode(id, forKey: "id")
        }
        if imagePath != nil{
            aCoder.encode(imagePath, forKey: "image_path")
        }
        if name != nil{
            aCoder.encode(name, forKey: "name")
        }
        if phone != nil{
            aCoder.encode(phone, forKey: "phone")
        }
        if updatedAt != nil{
            aCoder.encode(updatedAt, forKey: "updated_at")
        }
        
    }
    
}

class OplataObj : Mappable{
    
    var success : Bool?
    var AcsUrl : String?
    var PaReq : String?
    var TransactionId : Int?
    
    // AcsUrl PaReq TransactionId
    required init?(map: Map){}
    
    func mapping(map: Map)
    {
        success <- map["success"]
        AcsUrl <- map["AcsUrl"]
        PaReq <- map["PaReq"]
        TransactionId <- map["TransactionId"]
        
    }
    
}

class LocationResponse : NSObject, NSCoding, Mappable{
    
    var locations : [Location]?
    var success : Bool?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return LocationResponse()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        locations <- map["locations"]
        success <- map["success"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        locations = aDecoder.decodeObject(forKey: "locations") as? [Location]
        success = aDecoder.decodeObject(forKey: "success") as? Bool
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if locations != nil{
            aCoder.encode(locations, forKey: "locations")
        }
        if success != nil{
            aCoder.encode(success, forKey: "success")
        }
        
    }
    
}

class Location : NSObject, NSCoding, Mappable{
    
    var address : String?
    var createdAt : String?
    var id : Int?
    var latitude : String?
    var longitude : String?
    var partnerId : Int?
    var updatedAt : String?
    
    
    class func newInstance(map: Map) -> Mappable?{
        return Location()
    }
    required init?(map: Map){}
    private override init(){}
    
    func mapping(map: Map)
    {
        address <- map["address"]
        createdAt <- map["created_at"]
        id <- map["id"]
        latitude <- map["latitude"]
        longitude <- map["longitude"]
        partnerId <- map["partner_id"]
        updatedAt <- map["updated_at"]
        
    }
    
    /**
     * NSCoding required initializer.
     * Fills the data from the passed decoder
     */
    @objc required init(coder aDecoder: NSCoder)
    {
        address = aDecoder.decodeObject(forKey: "address") as? String
        createdAt = aDecoder.decodeObject(forKey: "created_at") as? String
        id = aDecoder.decodeObject(forKey: "id") as? Int
        latitude = aDecoder.decodeObject(forKey: "latitude") as? String
        longitude = aDecoder.decodeObject(forKey: "longitude") as? String
        partnerId = aDecoder.decodeObject(forKey: "partner_id") as? Int
        updatedAt = aDecoder.decodeObject(forKey: "updated_at") as? String
        
    }
    
    /**
     * NSCoding required method.
     * Encodes mode properties into the decoder
     */
    @objc func encode(with aCoder: NSCoder)
    {
        if address != nil{
            aCoder.encode(address, forKey: "address")
        }
        if createdAt != nil{
            aCoder.encode(createdAt, forKey: "created_at")
        }
        if id != nil{
            aCoder.encode(id, forKey: "id")
        }
        if latitude != nil{
            aCoder.encode(latitude, forKey: "latitude")
        }
        if longitude != nil{
            aCoder.encode(longitude, forKey: "longitude")
        }
        if partnerId != nil{
            aCoder.encode(partnerId, forKey: "partner_id")
        }
        if updatedAt != nil{
            aCoder.encode(updatedAt, forKey: "updated_at")
        }
        
    }
    
}
