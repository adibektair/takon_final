#import <YandexRuntime/YRTLocalError.h>

#import <yandex/maps/runtime/local_error.h>

#import <memory>

@interface YRTLocalError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::LocalError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::LocalError>)nativeLocalError;

@end
