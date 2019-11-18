#import <YandexRuntime/YRTDiskWriteAccessError.h>

#import <yandex/maps/runtime/local_error.h>

#import <memory>

@interface YRTDiskWriteAccessError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskWriteAccessError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskWriteAccessError>)nativeDiskWriteAccessError;

@end
