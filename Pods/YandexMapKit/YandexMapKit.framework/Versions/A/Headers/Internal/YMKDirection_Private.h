#import <YandexMapKit/YMKDirection.h>

#import <yandex/maps/mapkit/geometry/direction.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Direction, YMKDirection, void> {
    static ::yandex::maps::mapkit::geometry::Direction from(
        YMKDirection* platformDirection);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Direction, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKDirection*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Direction from(
        PlatformType platformDirection)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Direction, YMKDirection>::from(
            platformDirection);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Direction> {
    static YMKDirection* from(
        const ::yandex::maps::mapkit::geometry::Direction& direction);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
