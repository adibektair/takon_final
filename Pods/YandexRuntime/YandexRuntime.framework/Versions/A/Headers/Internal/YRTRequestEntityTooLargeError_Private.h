#import <YandexRuntime/YRTRequestEntityTooLargeError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTRequestEntityTooLargeError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::RequestEntityTooLargeError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::RequestEntityTooLargeError>)nativeRequestEntityTooLargeError;

@end
