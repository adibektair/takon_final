#import <YandexRuntime/YRTMiidManager.h>

#import <yandex/maps/runtime/init/miid_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace init {
namespace ios {

OnMiidReceived onMiidReceived(
    YRTMiidDelegate handler);
OnMiidError onMiidError(
    YRTMiidDelegate handler);

} // namespace ios
} // namespace init
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTMiidManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::init::MiidManager>&)native;

- (std::shared_ptr<::yandex::maps::runtime::init::MiidManager>)nativeMiidManager;
- (std::shared_ptr<::yandex::maps::runtime::init::MiidManager>)native;

@end
