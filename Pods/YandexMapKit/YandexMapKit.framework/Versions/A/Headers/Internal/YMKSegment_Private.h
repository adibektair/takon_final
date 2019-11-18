#import <YandexMapKit/YMKSegment.h>

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
struct ToNative<::yandex::maps::mapkit::geometry::Segment, YMKSegment, void> {
    static ::yandex::maps::mapkit::geometry::Segment from(
        YMKSegment* platformSegment);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Segment, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSegment*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Segment from(
        PlatformType platformSegment)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Segment, YMKSegment>::from(
            platformSegment);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Segment> {
    static YMKSegment* from(
        const ::yandex::maps::mapkit::geometry::Segment& segment);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
