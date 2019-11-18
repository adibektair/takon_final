#import <YandexRuntime/YRTNotFoundError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTNotFoundError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::NotFoundError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::NotFoundError>)nativeNotFoundError;

@end
