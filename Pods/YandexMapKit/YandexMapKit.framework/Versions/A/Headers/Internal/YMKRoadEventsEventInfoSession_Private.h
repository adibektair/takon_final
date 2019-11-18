#import <YandexMapKit/YMKRoadEventsEventInfoSession.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace road_events {
namespace ios {

EventInfoSession::OnEventInfoReceived onEventInfoReceived(
    YMKRoadEventsEventInfoSessionResponseHandler handler);
EventInfoSession::OnEventInfoError onEventInfoError(
    YMKRoadEventsEventInfoSessionResponseHandler handler);

} // namespace ios
} // namespace road_events
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKRoadEventsEventInfoSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::EventInfoSession>)native;

- (::yandex::maps::mapkit::road_events::EventInfoSession *)nativeEventInfoSession;

@end
