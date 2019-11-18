#import <YandexMapKit/YMKRoadEventsEntrySession.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace road_events {
namespace ios {

EntrySession::OnEntryReceived onEntryReceived(
    YMKRoadEventsEntrySessionResponseHandler handler);
EntrySession::OnEntryError onEntryError(
    YMKRoadEventsEntrySessionResponseHandler handler);

} // namespace ios
} // namespace road_events
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKRoadEventsEntrySession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::EntrySession>)native;

- (::yandex::maps::mapkit::road_events::EntrySession *)nativeEntrySession;

@end
