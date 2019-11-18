#import <YandexMapKit/YMKPolylineMapObject.h>

#import <yandex/maps/mapkit/map/polyline.h>

#import <memory>

@interface YMKPolylineMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::PolylineMapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::PolylineMapObject>)nativePolylineMapObject;

@end
