#import <YandexMapKit/YMKCluster.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/cluster.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKCluster ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::Cluster>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::Cluster>)nativeCluster;
- (std::shared_ptr<::yandex::maps::mapkit::map::Cluster>)native;

@end
