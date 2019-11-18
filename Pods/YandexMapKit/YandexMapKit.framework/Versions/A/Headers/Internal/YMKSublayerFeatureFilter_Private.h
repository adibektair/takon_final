#import <YandexMapKit/YMKSublayerFeatureFilter.h>

#import <yandex/maps/mapkit/map/sublayer_feature_filter.h>

#import <memory>

@interface YMKSublayerFeatureFilter ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::SublayerFeatureFilter>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::SublayerFeatureFilter>)nativeSublayerFeatureFilter;
- (std::shared_ptr<::yandex::maps::mapkit::map::SublayerFeatureFilter>)native;

@end
