#import <YandexRuntime/YRTNetworkRecorder.h>

#import <yandex/maps/runtime/network/internal/network_recording.h>

#import <memory>

@interface YRTNetworkRecorder ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>)nativeNetworkRecorder;
- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>)native;

@end
