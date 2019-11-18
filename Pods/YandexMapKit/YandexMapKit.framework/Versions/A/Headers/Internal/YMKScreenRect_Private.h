#import <YandexMapKit/YMKScreenRect.h>

#import <yandex/maps/mapkit/screen_types.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::ScreenRect, YMKScreenRect, void> {
    static ::yandex::maps::mapkit::ScreenRect from(
        YMKScreenRect* platformScreenRect);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::ScreenRect, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKScreenRect*>::value>::type> {
    static ::yandex::maps::mapkit::ScreenRect from(
        PlatformType platformScreenRect)
    {
        return ToNative<::yandex::maps::mapkit::ScreenRect, YMKScreenRect>::from(
            platformScreenRect);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::ScreenRect> {
    static YMKScreenRect* from(
        const ::yandex::maps::mapkit::ScreenRect& screenRect);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
