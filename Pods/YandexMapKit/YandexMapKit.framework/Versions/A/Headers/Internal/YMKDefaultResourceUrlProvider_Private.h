#import <YandexMapKit/YMKDefaultResourceUrlProvider.h>

#include <yandex/maps/mapkit/resource_url_provider/default_url_provider.h>

#include <memory>

@interface YMKDefaultResourceUrlProvider ()

- (id)initWithNative:(const std::shared_ptr<yandex::maps::mapkit::resource_url_provider::DefaultUrlProvider>&)native;

@end
