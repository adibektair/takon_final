//
//  MapViewController.swift
//  TAKON V2
//
//  Created by root user on 10/30/19.
//  Copyright © 2019 TAKON.ORG. All rights reserved.
//

import UIKit
import YandexMapKit
import CoreLocation
import Alamofire
import SDWebImage

class MapViewController: UIViewController, CLLocationManagerDelegate,  YMKClusterListener, YMKClusterTapListener {

    let locationManager = CLLocationManager()
    var partner : Partner?
    var locations = [Location]()
    var updated = false
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = partner?.name!
        let collection = mapView.mapWindow.map.mapObjects.addClusterizedPlacemarkCollection(with: self)

        self.getLocations(completionHandler: { locs in
            self.locations = locs
            if locs.count < 1{
                self.showAlert(title: "Просим прощения", message: "К сожалению, мы пока не добавили локации \(self.partner!.name!)")
            }
            for loc in locs{
                let point = YMKPoint(latitude: Double(Float(loc.latitude!)!), longitude: Double(Float(loc.longitude!)!))
                let img = UIImageView()
                img.frame = CGRect(x: 0, y: 0, width: 27, height: 27)
                img.cornerRadius(radius: 13, width: 1, color: .black)
                img.backgroundColor = .white
                img.sd_setImage(with:URL(string: imageUrl + (self.partner?.imagePath!.encodeUrl)!),
                                                      placeholderImage: #imageLiteral(resourceName: "kissclipart-yes-icon-clipart-computer-icons-clip-art-c0fb4dd5a5bf0bf1"),
                                                      options: [],
                                                      completed: { (image, error,cacheType, url) in
                
                                                        self.mapView.mapWindow.map.mapObjects.addPlacemark(with: point, view: YRTViewProvider(uiView: img), style: YMKIconStyle())
                                                  
                                                        
                })
           
                
            }
        })

        locationManager.requestWhenInUseAuthorization()
        if CLLocationManager.locationServicesEnabled() {
            locationManager.delegate = self
            locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
            locationManager.startUpdatingLocation()
            
        }
        // Do any additional setup after loading the view.
    }


    
    // MARK: - Outlets
    @IBOutlet var mapView: YMKMapView!
    
    static func open(vc: UIViewController, partner: Partner){
        let viewController = MapViewController(nibName: "MapViewController", bundle: nil)
        viewController.partner = partner
        
        if let nav = vc.navigationController {
            nav.pushViewController(viewController, animated: true)
        }
    }
   
    // Mark: Location
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let locValue: CLLocationCoordinate2D = manager.location?.coordinate else { return }
        
        let point = YMKPoint(latitude: locValue.latitude, longitude: locValue.longitude)
        self.mapView.mapWindow.map.mapObjects.addPlacemark(with: point, image: #imageLiteral(resourceName: "avatar"))
        
        mapView.mapWindow.map.move(
            with: YMKCameraPosition.init(target: YMKPoint(latitude: locValue.latitude, longitude: locValue.longitude), zoom: 15, azimuth: 0, tilt: 0),
            animationType: YMKAnimation(type: YMKAnimationType.smooth, duration: 5),
            cameraCallback: nil)
        print("locations = \(locValue.latitude) \(locValue.longitude)")
        locationManager.stopUpdatingLocation()
    }
    
    // Yandex map delegate
    func onClusterAdded(with cluster: YMKCluster) {
        // We setup cluster appearance and tap handler in this method
        cluster.appearance.setIconWith(#imageLiteral(resourceName: "kissclipart-yes-icon-clipart-computer-icons-clip-art-c0fb4dd5a5bf0bf1"))
        cluster.addClusterTapListener(with: self)
    }
    
    func onClusterTap(with cluster: YMKCluster) -> Bool {
        let alert = UIAlertController(
            title: "Tap",
            message: String(format: "Tapped cluster with %u items", cluster.size),
            preferredStyle: .alert)
        alert.addAction(
            UIAlertAction(title: "OK", style: .default, handler: nil))
        
        present(alert, animated: true, completion: nil)
        
        // We return true to notify map that the tap was handled and shouldn't be
        // propagated further.
        return true
    }
    
    func randomDouble() -> Double {
        return Double(arc4random()) / Double(UINT32_MAX)
    }
    
    func createPoints() -> [YMKPoint]{
        var points = [YMKPoint]()
//        for _ in 0..<PLACEMARKS_NUMBER {
//            let clusterCenter = CLUSTER_CENTERS.randomElement()!
//            let latitude = clusterCenter.latitude + randomDouble()  - 0.5
//            let longitude = clusterCenter.longitude + randomDouble()  - 0.5
//
//            points.append(YMKPoint(latitude: latitude, longitude: longitude))
//        }
        
        return points
    }
    
    
}
extension MapViewController{
    func getLocations(completionHandler: @escaping (_ params: [Location]) -> ()) {
        Alamofire.request("\(url)get-partners-locations", method: .post, parameters: ["token" : getToken(), "id" : self.partner?.id!], encoding: JSONEncoding.default, headers: nil).responseObject{
            (response: DataResponse<LocationResponse>) in
            if let code = response.response?.statusCode{
                if code == 401{
                    let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
                    let newViewController = storyBoard.instantiateViewController(withIdentifier: "start")
                    self.present(newViewController, animated: false, completion: nil)
                }
                if let info = response.result.value?.locations{
                    completionHandler(info)
                }
            }
            
            
        }
        
    }
}
