#import <YandexMapKit/YMKCircleMapObject.h>

#import <yandex/maps/mapkit/map/circle.h>

#import <memory>

@interface YMKCircleMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::CircleMapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::CircleMapObject>)nativeCircleMapObject;

@end
