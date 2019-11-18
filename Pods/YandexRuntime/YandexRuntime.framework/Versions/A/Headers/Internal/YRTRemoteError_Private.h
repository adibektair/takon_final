#import <YandexRuntime/YRTRemoteError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTRemoteError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::RemoteError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::RemoteError>)nativeRemoteError;

@end
