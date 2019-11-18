#import <YandexMapKit/YMKColoredPolylineMapObject.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/colored_polyline.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKColoredPolylineMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::ColoredPolylineMapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::ColoredPolylineMapObject>)nativeColoredPolylineMapObject;

@end
