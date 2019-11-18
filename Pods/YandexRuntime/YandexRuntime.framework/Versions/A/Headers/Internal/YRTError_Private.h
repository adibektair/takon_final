#import <YandexRuntime/YRTError.h>

#import <yandex/maps/runtime/error.h>

#import <memory>

@interface YRTError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::Error>&)native;

- (std::shared_ptr<::yandex::maps::runtime::Error>)nativeError;
- (std::shared_ptr<::yandex::maps::runtime::Error>)native;

@end
