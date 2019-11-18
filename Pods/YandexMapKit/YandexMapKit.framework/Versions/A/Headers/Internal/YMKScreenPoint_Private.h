#import <YandexMapKit/YMKScreenPoint.h>

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
struct ToNative<::yandex::maps::mapkit::ScreenPoint, YMKScreenPoint, void> {
    static ::yandex::maps::mapkit::ScreenPoint from(
        YMKScreenPoint* platformScreenPoint);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::ScreenPoint, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKScreenPoint*>::value>::type> {
    static ::yandex::maps::mapkit::ScreenPoint from(
        PlatformType platformScreenPoint)
    {
        return ToNative<::yandex::maps::mapkit::ScreenPoint, YMKScreenPoint>::from(
            platformScreenPoint);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::ScreenPoint> {
    static YMKScreenPoint* from(
        const ::yandex::maps::mapkit::ScreenPoint& screenPoint);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
