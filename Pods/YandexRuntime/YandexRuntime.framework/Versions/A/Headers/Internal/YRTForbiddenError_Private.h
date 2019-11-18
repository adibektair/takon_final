#import <YandexRuntime/YRTForbiddenError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTForbiddenError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::ForbiddenError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::ForbiddenError>)nativeForbiddenError;

@end
