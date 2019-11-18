#import <YandexMapKit/YMKZoomRange.h>

#import <yandex/maps/mapkit/zoom_range.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::ZoomRangeIdl, YMKZoomRange, void> {
    static ::yandex::maps::mapkit::ZoomRangeIdl from(
        YMKZoomRange* platformZoomRangeIdl);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::ZoomRangeIdl, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKZoomRange*>::value>::type> {
    static ::yandex::maps::mapkit::ZoomRangeIdl from(
        PlatformType platformZoomRangeIdl)
    {
        return ToNative<::yandex::maps::mapkit::ZoomRangeIdl, YMKZoomRange>::from(
            platformZoomRangeIdl);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::ZoomRangeIdl> {
    static YMKZoomRange* from(
        const ::yandex::maps::mapkit::ZoomRangeIdl& zoomRangeIdl);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
