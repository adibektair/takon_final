#import <YandexMapKit/YMKCircle.h>

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
struct ToNative<::yandex::maps::mapkit::geometry::Circle, YMKCircle, void> {
    static ::yandex::maps::mapkit::geometry::Circle from(
        YMKCircle* platformCircle);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Circle, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKCircle*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Circle from(
        PlatformType platformCircle)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Circle, YMKCircle>::from(
            platformCircle);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Circle> {
    static YMKCircle* from(
        const ::yandex::maps::mapkit::geometry::Circle& circle);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
