#import <YandexMapKit/YMKCameraPosition.h>

#import <yandex/maps/mapkit/map/camera_position.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::CameraPosition, YMKCameraPosition, void> {
    static ::yandex::maps::mapkit::map::CameraPosition from(
        YMKCameraPosition* platformCameraPosition);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::CameraPosition, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKCameraPosition*>::value>::type> {
    static ::yandex::maps::mapkit::map::CameraPosition from(
        PlatformType platformCameraPosition)
    {
        return ToNative<::yandex::maps::mapkit::map::CameraPosition, YMKCameraPosition>::from(
            platformCameraPosition);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::CameraPosition> {
    static YMKCameraPosition* from(
        const ::yandex::maps::mapkit::map::CameraPosition& cameraPosition);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
