#import <YandexRuntime/YRTClient.h>

#import <yandex/maps/runtime/rpc/client.h>

#import <memory>

@interface YRTClient ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::runtime::rpc::Client>)native;

- (::yandex::maps::runtime::rpc::Client *)nativeClient;

@end
