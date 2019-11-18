#import <YandexMapKit/YMKCoverage.h>

#import <yandex/maps/mapkit/coverage/coverage.h>

#import <memory>

@interface YMKCoverage ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::coverage::Coverage>)native;

- (::yandex::maps::mapkit::coverage::Coverage *)nativeCoverage;

@end
