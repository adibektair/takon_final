#import <YandexRuntime/YRTServiceManager.h>

#import <yandex/maps/runtime/ios/object.h>
#import <yandex/maps/runtime/rpc/internal/service_manager.h>

#import <memory>

@interface YRTServiceManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::rpc::internal::ServiceManager>&)native;

- (std::shared_ptr<::yandex::maps::runtime::rpc::internal::ServiceManager>)nativeServiceManager;
- (std::shared_ptr<::yandex::maps::runtime::rpc::internal::ServiceManager>)native;

@end
