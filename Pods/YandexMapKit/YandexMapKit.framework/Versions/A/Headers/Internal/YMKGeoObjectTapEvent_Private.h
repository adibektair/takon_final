#import <YandexMapKit/YMKGeoObjectTapEvent.h>

#import <yandex/maps/mapkit/layers/geo_object_tap_event.h>

#import <memory>

@interface YMKGeoObjectTapEvent ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapEvent>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapEvent>)nativeGeoObjectTapEvent;
- (std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapEvent>)native;

@end
