#import <YandexMapKit/YMKGeometry.h>

#import <yandex/maps/mapkit/geometry/geometry.h>
#import <yandex/maps/runtime/bindings/ios/to_native_fwd.h>
#import <yandex/maps/runtime/bindings/ios/to_platform_fwd.h>

#import <type_traits>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Geometry, id, void> {
    static ::yandex::maps::mapkit::geometry::Geometry from(
        id platformGeometry);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Geometry, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, id>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Geometry from(
        PlatformType platformGeometry)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Geometry, id>::from(
            platformGeometry);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Geometry> {
    static id from(
        const ::yandex::maps::mapkit::geometry::Geometry& geometry);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
