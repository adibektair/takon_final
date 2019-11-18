#import <YandexMapKit/YMKLocationManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/location/location_manager.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKLocationManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::LocationManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::LocationManager>)nativeLocationManager;
- (std::shared_ptr<::yandex::maps::mapkit::location::LocationManager>)native;

@end
