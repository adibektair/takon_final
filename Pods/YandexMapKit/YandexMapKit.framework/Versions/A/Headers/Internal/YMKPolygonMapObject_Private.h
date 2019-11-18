#import <YandexMapKit/YMKPolygonMapObject.h>

#import <yandex/maps/mapkit/map/polygon.h>

#import <memory>

@interface YMKPolygonMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::PolygonMapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::PolygonMapObject>)nativePolygonMapObject;

@end
