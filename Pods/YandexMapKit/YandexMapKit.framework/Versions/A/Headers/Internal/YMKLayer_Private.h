#import <YandexMapKit/YMKLayer.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/layers/layer.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::layers::Layer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::layers::Layer>)nativeLayer;
- (std::shared_ptr<::yandex::maps::mapkit::layers::Layer>)native;

@end
