#import <YandexRuntime/YRTDiskFullError.h>

#import <yandex/maps/runtime/local_error.h>

#import <memory>

@interface YRTDiskFullError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskFullError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskFullError>)nativeDiskFullError;

@end
