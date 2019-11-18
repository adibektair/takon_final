#import <YandexMapKit/YMKMapLoadStatistics.h>

#import <yandex/maps/mapkit/map/map_load_statistics.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::MapLoadStatistics, YMKMapLoadStatistics, void> {
    static ::yandex::maps::mapkit::map::MapLoadStatistics from(
        YMKMapLoadStatistics* platformMapLoadStatistics);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::MapLoadStatistics, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKMapLoadStatistics*>::value>::type> {
    static ::yandex::maps::mapkit::map::MapLoadStatistics from(
        PlatformType platformMapLoadStatistics)
    {
        return ToNative<::yandex::maps::mapkit::map::MapLoadStatistics, YMKMapLoadStatistics>::from(
            platformMapLoadStatistics);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::MapLoadStatistics> {
    static YMKMapLoadStatistics* from(
        const ::yandex::maps::mapkit::map::MapLoadStatistics& mapLoadStatistics);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
