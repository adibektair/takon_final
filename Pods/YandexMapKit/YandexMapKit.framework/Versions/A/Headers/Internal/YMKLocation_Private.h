#import <YandexMapKit/YMKLocation.h>

#import <yandex/maps/mapkit/location/location.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::location::Location, YMKLocation, void> {
    static ::yandex::maps::mapkit::location::Location from(
        YMKLocation* platformLocation);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::location::Location, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKLocation*>::value>::type> {
    static ::yandex::maps::mapkit::location::Location from(
        PlatformType platformLocation)
    {
        return ToNative<::yandex::maps::mapkit::location::Location, YMKLocation>::from(
            platformLocation);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::location::Location> {
    static YMKLocation* from(
        const ::yandex::maps::mapkit::location::Location& location);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
