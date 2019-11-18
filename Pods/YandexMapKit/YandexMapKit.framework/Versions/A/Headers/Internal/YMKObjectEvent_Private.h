#import <YandexMapKit/YMKObjectEvent.h>

#import <yandex/maps/mapkit/layers/object_event.h>

#import <memory>

@interface YMKObjectEvent ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::layers::ObjectEvent>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::layers::ObjectEvent>)nativeObjectEvent;
- (std::shared_ptr<::yandex::maps::mapkit::layers::ObjectEvent>)native;

@end
