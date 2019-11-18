#import <YandexMapKit/YMKVisibleRegion.h>

#import <yandex/maps/mapkit/map/visible_region.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::VisibleRegion, YMKVisibleRegion, void> {
    static ::yandex::maps::mapkit::map::VisibleRegion from(
        YMKVisibleRegion* platformVisibleRegion);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::VisibleRegion, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKVisibleRegion*>::value>::type> {
    static ::yandex::maps::mapkit::map::VisibleRegion from(
        PlatformType platformVisibleRegion)
    {
        return ToNative<::yandex::maps::mapkit::map::VisibleRegion, YMKVisibleRegion>::from(
            platformVisibleRegion);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::VisibleRegion> {
    static YMKVisibleRegion* from(
        const ::yandex::maps::mapkit::map::VisibleRegion& visibleRegion);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
