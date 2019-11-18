#import <YandexMapKit/YMKBoundingBox.h>

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
struct ToNative<::yandex::maps::mapkit::geometry::BoundingBox, YMKBoundingBox, void> {
    static ::yandex::maps::mapkit::geometry::BoundingBox from(
        YMKBoundingBox* platformBoundingBox);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::BoundingBox, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKBoundingBox*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::BoundingBox from(
        PlatformType platformBoundingBox)
    {
        return ToNative<::yandex::maps::mapkit::geometry::BoundingBox, YMKBoundingBox>::from(
            platformBoundingBox);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::BoundingBox> {
    static YMKBoundingBox* from(
        const ::yandex::maps::mapkit::geometry::BoundingBox& boundingBox);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
