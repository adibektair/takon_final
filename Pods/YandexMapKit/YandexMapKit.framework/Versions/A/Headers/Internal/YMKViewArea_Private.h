#import <YandexMapKit/YMKViewArea.h>

#import <yandex/maps/mapkit/location/view_area.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::location::ViewArea, YMKViewArea, void> {
    static ::yandex::maps::mapkit::location::ViewArea from(
        YMKViewArea* platformViewArea);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::location::ViewArea, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKViewArea*>::value>::type> {
    static ::yandex::maps::mapkit::location::ViewArea from(
        PlatformType platformViewArea)
    {
        return ToNative<::yandex::maps::mapkit::location::ViewArea, YMKViewArea>::from(
            platformViewArea);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::location::ViewArea> {
    static YMKViewArea* from(
        const ::yandex::maps::mapkit::location::ViewArea& viewArea);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
