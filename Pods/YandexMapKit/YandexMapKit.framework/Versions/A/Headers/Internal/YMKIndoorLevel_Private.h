#import <YandexMapKit/YMKIndoorLevel.h>

#import <yandex/maps/mapkit/indoor/indoor_plan.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::indoor::IndoorLevel, YMKIndoorLevel, void> {
    static ::yandex::maps::mapkit::indoor::IndoorLevel from(
        YMKIndoorLevel* platformIndoorLevel);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::indoor::IndoorLevel, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKIndoorLevel*>::value>::type> {
    static ::yandex::maps::mapkit::indoor::IndoorLevel from(
        PlatformType platformIndoorLevel)
    {
        return ToNative<::yandex::maps::mapkit::indoor::IndoorLevel, YMKIndoorLevel>::from(
            platformIndoorLevel);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::indoor::IndoorLevel> {
    static YMKIndoorLevel* from(
        const ::yandex::maps::mapkit::indoor::IndoorLevel& indoorLevel);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
