#import <YandexMapKit/YMKCompositeIcon.h>

#import <yandex/maps/mapkit/map/composite_icon.h>

#import <memory>

@interface YMKCompositeIcon ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::CompositeIcon>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::CompositeIcon>)nativeCompositeIcon;
- (std::shared_ptr<::yandex::maps::mapkit::map::CompositeIcon>)native;

@end
