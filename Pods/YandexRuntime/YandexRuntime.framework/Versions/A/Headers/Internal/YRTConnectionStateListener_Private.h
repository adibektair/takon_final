#import <YandexRuntime/YRTConnectionStateListener.h>

#import <yandex/maps/runtime/rpc/connection_state_listener.h>

#import <memory>

@interface YRTConnectionStateListener ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::rpc::ConnectionStateListener>&)native;

- (std::shared_ptr<::yandex::maps::runtime::rpc::ConnectionStateListener>)nativeConnectionStateListener;
- (std::shared_ptr<::yandex::maps::runtime::rpc::ConnectionStateListener>)native;

@end
