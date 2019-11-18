#import <YandexMapKit/YMKLogoAlignment.h>

#import <yandex/maps/mapkit/logo/alignment.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::logo::Alignment, YMKLogoAlignment, void> {
    static ::yandex::maps::mapkit::logo::Alignment from(
        YMKLogoAlignment* platformAlignment);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::logo::Alignment, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKLogoAlignment*>::value>::type> {
    static ::yandex::maps::mapkit::logo::Alignment from(
        PlatformType platformAlignment)
    {
        return ToNative<::yandex::maps::mapkit::logo::Alignment, YMKLogoAlignment>::from(
            platformAlignment);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::logo::Alignment> {
    static YMKLogoAlignment* from(
        const ::yandex::maps::mapkit::logo::Alignment& alignment);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
