#import <YandexMapKit/YMKIndoorLayer.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/indoor_layer/indoor_layer.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKIndoorLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorLayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorLayer>)nativeIndoorLayer;
- (std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorLayer>)native;

@end
