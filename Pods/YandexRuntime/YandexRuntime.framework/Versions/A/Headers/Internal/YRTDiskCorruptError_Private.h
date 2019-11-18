#import <YandexRuntime/YRTDiskCorruptError.h>

#import <yandex/maps/runtime/local_error.h>

#import <memory>

@interface YRTDiskCorruptError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskCorruptError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskCorruptError>)nativeDiskCorruptError;

@end
