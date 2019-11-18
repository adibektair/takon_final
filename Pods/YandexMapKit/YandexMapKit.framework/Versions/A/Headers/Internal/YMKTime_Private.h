#import <YandexMapKit/YMKTime.h>

#import <yandex/maps/mapkit/time.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Time, YMKTime, void> {
    static ::yandex::maps::mapkit::Time from(
        YMKTime* platformTime);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Time, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKTime*>::value>::type> {
    static ::yandex::maps::mapkit::Time from(
        PlatformType platformTime)
    {
        return ToNative<::yandex::maps::mapkit::Time, YMKTime>::from(
            platformTime);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Time> {
    static YMKTime* from(
        const ::yandex::maps::mapkit::Time& time);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
