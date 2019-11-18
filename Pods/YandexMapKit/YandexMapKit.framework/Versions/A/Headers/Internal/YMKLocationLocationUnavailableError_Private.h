#import <YandexMapKit/YMKLocationLocationUnavailableError.h>

#import <yandex/maps/mapkit/location/error.h>

#import <memory>

@interface YMKLocationLocationUnavailableError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::LocationUnavailableError>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::LocationUnavailableError>)nativeLocationUnavailableError;

@end
