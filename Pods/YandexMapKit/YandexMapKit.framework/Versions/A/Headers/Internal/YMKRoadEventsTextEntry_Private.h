#import <YandexMapKit/YMKRoadEventsTextEntry.h>

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
struct ToNative<::yandex::maps::mapkit::road_events::TextEntry, YMKRoadEventsTextEntry, void> {
    static ::yandex::maps::mapkit::road_events::TextEntry from(
        YMKRoadEventsTextEntry* platformTextEntry);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::road_events::TextEntry, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKRoadEventsTextEntry*>::value>::type> {
    static ::yandex::maps::mapkit::road_events::TextEntry from(
        PlatformType platformTextEntry)
    {
        return ToNative<::yandex::maps::mapkit::road_events::TextEntry, YMKRoadEventsTextEntry>::from(
            platformTextEntry);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::road_events::TextEntry> {
    static YMKRoadEventsTextEntry* from(
        const ::yandex::maps::mapkit::road_events::TextEntry& textEntry);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
