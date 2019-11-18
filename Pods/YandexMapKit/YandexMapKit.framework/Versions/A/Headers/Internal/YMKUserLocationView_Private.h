#import <YandexMapKit/YMKUserLocationView.h>

#import <yandex/maps/mapkit/user_location/user_location.h>

#import <memory>

@interface YMKUserLocationView ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>)nativeUserLocationView;
- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>)native;

@end
