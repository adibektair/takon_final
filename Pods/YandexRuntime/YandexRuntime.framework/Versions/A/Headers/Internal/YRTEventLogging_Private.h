#import <YandexRuntime/YRTEventLogging.h>
#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/runtime/ios/object.h>
#import <yandex/maps/runtime/recording/event_logging.h>

#import <memory>

@interface YRTEventLogging ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>&)native;

- (std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>)nativeEventLogging;
- (std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>)native;

@end
