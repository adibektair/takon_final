#import <YandexMapKit/YMKArrow.h>

#import <yandex/maps/mapkit/map/arrow.h>

#import <memory>

@interface YMKArrow ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::Arrow>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::Arrow>)nativeArrow;
- (std::shared_ptr<::yandex::maps::mapkit::map::Arrow>)native;

@end
