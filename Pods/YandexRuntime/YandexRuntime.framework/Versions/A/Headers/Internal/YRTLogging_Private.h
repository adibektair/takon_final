#import <YandexRuntime/YRTLogging.h>
#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/runtime/ios/object.h>
#import <yandex/maps/runtime/logging/subscription_logger.h>

#import <memory>

@interface YRTLogging ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::logging::Logging>&)native;

- (std::shared_ptr<::yandex::maps::runtime::logging::Logging>)nativeLogging;
- (std::shared_ptr<::yandex::maps::runtime::logging::Logging>)native;

@end
