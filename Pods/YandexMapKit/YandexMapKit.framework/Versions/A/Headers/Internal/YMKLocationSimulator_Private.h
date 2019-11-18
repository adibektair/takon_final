#import <YandexMapKit/YMKLocationSimulator.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/location/location_simulator.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKLocationSimulator ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulator>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulator>)nativeLocationSimulator;

@end
