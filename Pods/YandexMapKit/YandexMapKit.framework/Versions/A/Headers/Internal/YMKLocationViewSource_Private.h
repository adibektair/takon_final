#import <YandexMapKit/YMKLocationViewSource.h>

#import <yandex/maps/mapkit/location/location_view_source.h>

#import <memory>

@interface YMKLocationViewSource ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::LocationViewSource>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::LocationViewSource>)nativeLocationViewSource;
- (std::shared_ptr<::yandex::maps::mapkit::location::LocationViewSource>)native;

@end
