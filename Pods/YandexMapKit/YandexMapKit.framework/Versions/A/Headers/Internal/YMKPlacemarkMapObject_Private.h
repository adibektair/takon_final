#import <YandexMapKit/YMKPlacemarkMapObject.h>

#import <yandex/maps/mapkit/map/placemark.h>

#import <memory>

@interface YMKPlacemarkMapObject ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::PlacemarkMapObject>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::PlacemarkMapObject>)nativePlacemarkMapObject;

@end
