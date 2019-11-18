#import <YandexRuntime/YRTNetworkError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTNetworkError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::NetworkError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::NetworkError>)nativeNetworkError;

@end
