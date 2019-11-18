#import <YandexMapKit/YMKRoadEventsFeedSession.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace road_events {
namespace ios {

FeedSession::OnFeedReceived onFeedReceived(
    YMKRoadEventsFeedSessionResponseHandler handler);
FeedSession::OnFeedError onFeedError(
    YMKRoadEventsFeedSessionResponseHandler handler);

} // namespace ios
} // namespace road_events
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKRoadEventsFeedSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::FeedSession>)native;

- (::yandex::maps::mapkit::road_events::FeedSession *)nativeFeedSession;

@end
