#import <YandexMapKit/YMKDummyLocationManager.h>

#import <yandex/maps/mapkit/location/dummy_location_manager.h>

#import <memory>

@interface YMKDummyLocationManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::DummyLocationManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::DummyLocationManager>)nativeDummyLocationManager;

@end
