#import <YandexMapKit/YMKSubpolyline.h>

#import <yandex/maps/mapkit/geometry/geometry.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Subpolyline, YMKSubpolyline, void> {
    static ::yandex::maps::mapkit::geometry::Subpolyline from(
        YMKSubpolyline* platformSubpolyline);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Subpolyline, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSubpolyline*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Subpolyline from(
        PlatformType platformSubpolyline)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Subpolyline, YMKSubpolyline>::from(
            platformSubpolyline);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Subpolyline> {
    static YMKSubpolyline* from(
        const ::yandex::maps::mapkit::geometry::Subpolyline& subpolyline);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
