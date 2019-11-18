#import <YandexMapKit/YMKUserLocationLayer.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/user_location/user_location.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKUserLocationLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>)nativeUserLocationLayer;
- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>)native;

@end
