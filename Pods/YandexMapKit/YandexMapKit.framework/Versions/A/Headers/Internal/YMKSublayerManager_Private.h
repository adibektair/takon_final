#import <YandexMapKit/YMKSublayerManager.h>

#import <yandex/maps/mapkit/map/sublayer_manager.h>

#import <memory>

@interface YMKSublayerManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::SublayerManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::SublayerManager>)nativeSublayerManager;
- (std::shared_ptr<::yandex::maps::mapkit::map::SublayerManager>)native;

@end
