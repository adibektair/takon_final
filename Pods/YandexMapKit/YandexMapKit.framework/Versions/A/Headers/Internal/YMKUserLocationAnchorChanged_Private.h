#import <YandexMapKit/YMKUserLocationAnchorChanged.h>

#import <yandex/maps/mapkit/user_location/user_location.h>

#import <memory>

@interface YMKUserLocationAnchorChanged ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationAnchorChanged>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationAnchorChanged>)nativeUserLocationAnchorChanged;

@end
