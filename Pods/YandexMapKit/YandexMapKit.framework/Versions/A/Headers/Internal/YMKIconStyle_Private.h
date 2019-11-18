#import <YandexMapKit/YMKIconStyle.h>

#import <yandex/maps/mapkit/map/icon_style.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::IconStyle, YMKIconStyle, void> {
    static ::yandex::maps::mapkit::map::IconStyle from(
        YMKIconStyle* platformIconStyle);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::IconStyle, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKIconStyle*>::value>::type> {
    static ::yandex::maps::mapkit::map::IconStyle from(
        PlatformType platformIconStyle)
    {
        return ToNative<::yandex::maps::mapkit::map::IconStyle, YMKIconStyle>::from(
            platformIconStyle);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::IconStyle> {
    static YMKIconStyle* from(
        const ::yandex::maps::mapkit::map::IconStyle& iconStyle);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
