#import <YandexMapKit/YMKMapWindow.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/map_window.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKMapWindow ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::MapWindow>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::MapWindow>)nativeMapWindow;
- (std::shared_ptr<::yandex::maps::mapkit::map::MapWindow>)native;

@end
