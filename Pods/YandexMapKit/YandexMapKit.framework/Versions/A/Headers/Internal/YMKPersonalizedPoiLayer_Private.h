#import <YandexMapKit/YMKPersonalizedPoiLayer.h>

#import <yandex/maps/mapkit/personalized_poi/personalized_poi_layer.h>

#import <memory>

@interface YMKPersonalizedPoiLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::personalized_poi::PersonalizedPoiLayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::personalized_poi::PersonalizedPoiLayer>)nativePersonalizedPoiLayer;
- (std::shared_ptr<::yandex::maps::mapkit::personalized_poi::PersonalizedPoiLayer>)native;

@end
