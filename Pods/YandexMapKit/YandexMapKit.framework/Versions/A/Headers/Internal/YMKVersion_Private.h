#import <YandexMapKit/YMKVersion.h>

#import <yandex/maps/mapkit/version.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Version, YMKVersion, void> {
    static ::yandex::maps::mapkit::Version from(
        YMKVersion* platformVersion);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Version, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKVersion*>::value>::type> {
    static ::yandex::maps::mapkit::Version from(
        PlatformType platformVersion)
    {
        return ToNative<::yandex::maps::mapkit::Version, YMKVersion>::from(
            platformVersion);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Version> {
    static YMKVersion* from(
        const ::yandex::maps::mapkit::Version& version);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
