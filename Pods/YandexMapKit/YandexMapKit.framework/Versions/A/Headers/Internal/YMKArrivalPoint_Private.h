#import <YandexMapKit/YMKArrivalPoint.h>

#import <yandex/maps/mapkit/arrival/arrival_object_metadata.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::arrival::ArrivalPoint, YMKArrivalPoint, void> {
    static ::yandex::maps::mapkit::arrival::ArrivalPoint from(
        YMKArrivalPoint* platformArrivalPoint);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::arrival::ArrivalPoint, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKArrivalPoint*>::value>::type> {
    static ::yandex::maps::mapkit::arrival::ArrivalPoint from(
        PlatformType platformArrivalPoint)
    {
        return ToNative<::yandex::maps::mapkit::arrival::ArrivalPoint, YMKArrivalPoint>::from(
            platformArrivalPoint);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::arrival::ArrivalPoint> {
    static YMKArrivalPoint* from(
        const ::yandex::maps::mapkit::arrival::ArrivalPoint& arrivalPoint);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
