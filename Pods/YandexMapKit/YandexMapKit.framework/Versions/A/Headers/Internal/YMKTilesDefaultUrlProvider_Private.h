#import <YandexMapKit/YMKTilesDefaultUrlProvider.h>

#include <yandex/maps/mapkit/tiles/default_url_provider.h>

#include <memory>

@interface YMKTilesDefaultUrlProvider ()

- (id)initWithNative:(const std::shared_ptr<yandex::maps::mapkit::tiles::DefaultUrlProvider>&)native;

@end
