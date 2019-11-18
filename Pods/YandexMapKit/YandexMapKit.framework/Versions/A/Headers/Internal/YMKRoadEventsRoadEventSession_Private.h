#import <YandexMapKit/YMKRoadEventsRoadEventSession.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace road_events {
namespace ios {

RoadEventSession::OnRoadEventReceived onRoadEventReceived(
    YMKRoadEventsRoadEventSessionResponseHandler handler);
RoadEventSession::OnRoadEventError onRoadEventError(
    YMKRoadEventsRoadEventSessionResponseHandler handler);

} // namespace ios
} // namespace road_events
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKRoadEventsRoadEventSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::RoadEventSession>)native;

- (::yandex::maps::mapkit::road_events::RoadEventSession *)nativeRoadEventSession;

@end
