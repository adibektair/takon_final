#import <YandexMapKit/YMKMapObject.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/map_object.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::MapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::MapObject>)nativeMapObject;
- (std::shared_ptr<::yandex::maps::mapkit::map::MapObject>)native;

@end
