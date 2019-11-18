#import <YandexMapKit/YMKUserLocationIconChanged.h>

#import <yandex/maps/mapkit/user_location/user_location.h>

#import <memory>

@interface YMKUserLocationIconChanged ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationIconChanged>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationIconChanged>)nativeUserLocationIconChanged;

@end
