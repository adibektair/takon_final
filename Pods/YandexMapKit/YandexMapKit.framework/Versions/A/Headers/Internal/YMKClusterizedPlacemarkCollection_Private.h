#import <YandexMapKit/YMKClusterizedPlacemarkCollection.h>

#import <yandex/maps/mapkit/map/clusterized_placemark_collection.h>

#import <memory>

@interface YMKClusterizedPlacemarkCollection ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::ClusterizedPlacemarkCollection>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::ClusterizedPlacemarkCollection>)nativeClusterizedPlacemarkCollection;

@end
