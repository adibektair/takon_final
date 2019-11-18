#import <YandexMapKit/YMKOfflineCacheRegion.h>

#import <yandex/maps/mapkit/offline_cache/region.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::offline_cache::Region, YMKOfflineCacheRegion, void> {
    static ::yandex::maps::mapkit::offline_cache::Region from(
        YMKOfflineCacheRegion* platformRegion);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::offline_cache::Region, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKOfflineCacheRegion*>::value>::type> {
    static ::yandex::maps::mapkit::offline_cache::Region from(
        PlatformType platformRegion)
    {
        return ToNative<::yandex::maps::mapkit::offline_cache::Region, YMKOfflineCacheRegion>::from(
            platformRegion);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::offline_cache::Region> {
    static YMKOfflineCacheRegion* from(
        const ::yandex::maps::mapkit::offline_cache::Region& region);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
