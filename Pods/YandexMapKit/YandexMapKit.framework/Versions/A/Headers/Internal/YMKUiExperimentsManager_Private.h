#import <YandexMapKit/YMKUiExperimentsManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/experiments/ui_experiments_manager.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKUiExperimentsManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>)nativeUiExperimentsManager;
- (std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>)native;

@end
