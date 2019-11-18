#import <YandexMapKit/YMKAnimation.h>

#import <yandex/maps/mapkit/animation.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Animation, YMKAnimation, void> {
    static ::yandex::maps::mapkit::Animation from(
        YMKAnimation* platformAnimation);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Animation, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAnimation*>::value>::type> {
    static ::yandex::maps::mapkit::Animation from(
        PlatformType platformAnimation)
    {
        return ToNative<::yandex::maps::mapkit::Animation, YMKAnimation>::from(
            platformAnimation);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Animation> {
    static YMKAnimation* from(
        const ::yandex::maps::mapkit::Animation& animation);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
