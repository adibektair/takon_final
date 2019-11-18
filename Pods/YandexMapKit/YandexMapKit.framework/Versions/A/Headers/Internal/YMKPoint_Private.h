#import <YandexMapKit/YMKPoint.h>

#import <yandex/maps/mapkit/geometry/point.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Point, YMKPoint, void> {
    static ::yandex::maps::mapkit::geometry::Point from(
        YMKPoint* platformPoint);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Point, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKPoint*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Point from(
        PlatformType platformPoint)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Point, YMKPoint>::from(
            platformPoint);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Point> {
    static YMKPoint* from(
        const ::yandex::maps::mapkit::geometry::Point& point);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
