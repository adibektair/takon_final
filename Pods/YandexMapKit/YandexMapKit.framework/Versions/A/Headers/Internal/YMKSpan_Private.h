#import <YandexMapKit/YMKSpan.h>

#import <yandex/maps/mapkit/geometry/span.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Span, YMKSpan, void> {
    static ::yandex::maps::mapkit::geometry::Span from(
        YMKSpan* platformSpan);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Span, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSpan*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Span from(
        PlatformType platformSpan)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Span, YMKSpan>::from(
            platformSpan);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Span> {
    static YMKSpan* from(
        const ::yandex::maps::mapkit::geometry::Span& span);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
