#import <YandexMapKit/YMKXYPoint.h>

#import <yandex/maps/mapkit/geometry/geo/xy_point.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::geo::XYPoint, YMKXYPoint, void> {
    static ::yandex::maps::mapkit::geometry::geo::XYPoint from(
        YMKXYPoint* platformXYPoint);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::geo::XYPoint, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKXYPoint*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::geo::XYPoint from(
        PlatformType platformXYPoint)
    {
        return ToNative<::yandex::maps::mapkit::geometry::geo::XYPoint, YMKXYPoint>::from(
            platformXYPoint);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::geo::XYPoint> {
    static YMKXYPoint* from(
        const ::yandex::maps::mapkit::geometry::geo::XYPoint& xYPoint);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
