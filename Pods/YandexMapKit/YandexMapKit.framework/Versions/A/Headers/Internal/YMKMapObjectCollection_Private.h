#import <YandexMapKit/YMKMapObjectCollection.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/map_object_collection.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKMapObjectCollection ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollection>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollection>)nativeMapObjectCollection;

@end
