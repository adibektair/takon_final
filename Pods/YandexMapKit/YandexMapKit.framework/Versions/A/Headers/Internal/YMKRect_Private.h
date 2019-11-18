#import <YandexMapKit/YMKRect.h>

#import <yandex/maps/mapkit/map/rect.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::Rect, YMKRect, void> {
    static ::yandex::maps::mapkit::map::Rect from(
        YMKRect* platformRect);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::Rect, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKRect*>::value>::type> {
    static ::yandex::maps::mapkit::map::Rect from(
        PlatformType platformRect)
    {
        return ToNative<::yandex::maps::mapkit::map::Rect, YMKRect>::from(
            platformRect);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::Rect> {
    static YMKRect* from(
        const ::yandex::maps::mapkit::map::Rect& rect);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
