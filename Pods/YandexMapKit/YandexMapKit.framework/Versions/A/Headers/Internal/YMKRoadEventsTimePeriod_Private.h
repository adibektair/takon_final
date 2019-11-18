#import <YandexMapKit/YMKRoadEventsTimePeriod.h>

#import <yandex/maps/mapkit/road_events/road_events.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::road_events::TimePeriod, YMKRoadEventsTimePeriod, void> {
    static ::yandex::maps::mapkit::road_events::TimePeriod from(
        YMKRoadEventsTimePeriod* platformTimePeriod);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::road_events::TimePeriod, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKRoadEventsTimePeriod*>::value>::type> {
    static ::yandex::maps::mapkit::road_events::TimePeriod from(
        PlatformType platformTimePeriod)
    {
        return ToNative<::yandex::maps::mapkit::road_events::TimePeriod, YMKRoadEventsTimePeriod>::from(
            platformTimePeriod);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::road_events::TimePeriod> {
    static YMKRoadEventsTimePeriod* from(
        const ::yandex::maps::mapkit::road_events::TimePeriod& timePeriod);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
