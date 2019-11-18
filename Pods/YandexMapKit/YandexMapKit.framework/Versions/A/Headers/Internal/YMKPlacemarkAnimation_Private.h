#import <YandexMapKit/YMKPlacemarkAnimation.h>

#import <yandex/maps/mapkit/map/placemark_animation.h>

#import <memory>

@interface YMKPlacemarkAnimation ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::PlacemarkAnimation>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::PlacemarkAnimation>)nativePlacemarkAnimation;
- (std::shared_ptr<::yandex::maps::mapkit::map::PlacemarkAnimation>)native;

@end
