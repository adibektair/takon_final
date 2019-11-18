#import <YandexMapKit/YMKPolylinePosition.h>

#import <yandex/maps/mapkit/geometry/geometry.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, YMKPolylinePosition, void> {
    static ::yandex::maps::mapkit::geometry::PolylinePosition from(
        YMKPolylinePosition* platformPolylinePosition);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKPolylinePosition*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::PolylinePosition from(
        PlatformType platformPolylinePosition)
    {
        return ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, YMKPolylinePosition>::from(
            platformPolylinePosition);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::PolylinePosition> {
    static YMKPolylinePosition* from(
        const ::yandex::maps::mapkit::geometry::PolylinePosition& polylinePosition);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
