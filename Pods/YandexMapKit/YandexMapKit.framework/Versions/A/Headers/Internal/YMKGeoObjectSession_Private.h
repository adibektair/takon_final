#import <YandexMapKit/YMKGeoObjectSession.h>

#import <yandex/maps/mapkit/geo_object_session.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace ios {

GeoObjectSession::OnGeoObjectResult onGeoObjectResult(
    YMKGeoObjectSessionGeoObjectHandler handler);
GeoObjectSession::OnGeoObjectError onGeoObjectError(
    YMKGeoObjectSessionGeoObjectHandler handler);

} // namespace ios
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKGeoObjectSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::GeoObjectSession>)native;

- (::yandex::maps::mapkit::GeoObjectSession *)nativeGeoObjectSession;

@end
