#import <YandexRuntime/YRTNetworkPlayer.h>

#import <yandex/maps/runtime/network/internal/network_recording.h>

#import <memory>

@interface YRTNetworkPlayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>)nativeNetworkPlayer;
- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>)native;

@end
