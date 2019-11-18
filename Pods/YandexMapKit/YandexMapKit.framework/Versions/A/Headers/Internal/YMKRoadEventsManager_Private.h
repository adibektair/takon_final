#import <YandexMapKit/YMKRoadEventsManager.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

@interface YMKRoadEventsManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::RoadEventsManager>)native;

- (::yandex::maps::mapkit::road_events::RoadEventsManager *)nativeRoadEventsManager;

@end
