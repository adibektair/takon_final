#import <YandexRuntime/YRTUpgradeRequiredError.h>

#import <yandex/maps/runtime/config/error.h>

#import <memory>

@interface YRTUpgradeRequiredError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::config::UpgradeRequiredError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::config::UpgradeRequiredError>)nativeUpgradeRequiredError;

@end
