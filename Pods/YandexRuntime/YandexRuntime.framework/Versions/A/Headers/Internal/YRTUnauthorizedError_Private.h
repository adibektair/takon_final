#import <YandexRuntime/YRTUnauthorizedError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTUnauthorizedError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::UnauthorizedError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::UnauthorizedError>)nativeUnauthorizedError;

@end
