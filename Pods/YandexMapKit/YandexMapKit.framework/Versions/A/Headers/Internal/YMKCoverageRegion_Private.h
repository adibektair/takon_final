#import <YandexMapKit/YMKCoverageRegion.h>

#import <yandex/maps/mapkit/coverage/region.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::coverage::Region, YMKCoverageRegion, void> {
    static ::yandex::maps::mapkit::coverage::Region from(
        YMKCoverageRegion* platformRegion);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::coverage::Region, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKCoverageRegion*>::value>::type> {
    static ::yandex::maps::mapkit::coverage::Region from(
        PlatformType platformRegion)
    {
        return ToNative<::yandex::maps::mapkit::coverage::Region, YMKCoverageRegion>::from(
            platformRegion);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::coverage::Region> {
    static YMKCoverageRegion* from(
        const ::yandex::maps::mapkit::coverage::Region& region);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
