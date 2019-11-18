#import <YandexRuntime/YRTBadRequestError.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTBadRequestError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::BadRequestError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::BadRequestError>)nativeBadRequestError;

@end
