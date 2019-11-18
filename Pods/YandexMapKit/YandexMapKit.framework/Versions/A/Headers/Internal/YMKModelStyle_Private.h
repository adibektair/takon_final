#import <YandexMapKit/YMKModelStyle.h>

#import <yandex/maps/mapkit/map/model_style.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::ModelStyle, YMKModelStyle, void> {
    static ::yandex::maps::mapkit::map::ModelStyle from(
        YMKModelStyle* platformModelStyle);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::ModelStyle, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKModelStyle*>::value>::type> {
    static ::yandex::maps::mapkit::map::ModelStyle from(
        PlatformType platformModelStyle)
    {
        return ToNative<::yandex::maps::mapkit::map::ModelStyle, YMKModelStyle>::from(
            platformModelStyle);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::ModelStyle> {
    static YMKModelStyle* from(
        const ::yandex::maps::mapkit::map::ModelStyle& modelStyle);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
