#import <YandexMapKit/YMKMapKit.h>

#import <yandex/maps/mapkit/mapkit.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKMapKit ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::MapKit>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::MapKit>)nativeMapKit;
- (std::shared_ptr<::yandex::maps::mapkit::MapKit>)native;

@end
