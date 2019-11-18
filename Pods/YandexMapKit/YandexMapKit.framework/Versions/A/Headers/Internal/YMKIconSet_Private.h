#import <YandexMapKit/YMKIconSet.h>

#import <yandex/maps/mapkit/map/icon_set.h>

#import <memory>

@interface YMKIconSet ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::IconSet>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::IconSet>)nativeIconSet;
- (std::shared_ptr<::yandex::maps::mapkit::map::IconSet>)native;

@end
