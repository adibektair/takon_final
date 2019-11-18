#import <YandexMapKit/YMKSublayer.h>

#import <yandex/maps/mapkit/map/sublayer.h>

#import <memory>

@interface YMKSublayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::Sublayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::Sublayer>)nativeSublayer;
- (std::shared_ptr<::yandex::maps::mapkit::map::Sublayer>)native;

@end
