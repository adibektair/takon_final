#import <YandexMapKit/YMKPlacemarksStyler.h>

#import <yandex/maps/mapkit/map/placemarks_styler.h>

#import <memory>

@interface YMKPlacemarksStyler ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::PlacemarksStyler>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::PlacemarksStyler>)nativePlacemarksStyler;
- (std::shared_ptr<::yandex::maps::mapkit::map::PlacemarksStyler>)native;

@end
