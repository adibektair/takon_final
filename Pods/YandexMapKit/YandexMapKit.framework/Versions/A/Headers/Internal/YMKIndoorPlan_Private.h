#import <YandexMapKit/YMKIndoorPlan.h>

#import <yandex/maps/mapkit/indoor/indoor_plan.h>

#import <memory>

@interface YMKIndoorPlan ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorPlan>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorPlan>)nativeIndoorPlan;
- (std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorPlan>)native;

@end
