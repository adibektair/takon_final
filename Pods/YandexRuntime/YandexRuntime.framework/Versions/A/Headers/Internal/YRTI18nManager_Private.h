#import <YandexRuntime/YRTI18nManager.h>

#import <yandex/maps/runtime/i18n/i18n_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace i18n {
namespace ios {

OnLocaleUpdated onLocaleUpdated(
    YRTLocaleUpdateDelegate handler);
OnLocaleUpdateError onLocaleUpdateError(
    YRTLocaleUpdateDelegate handler);

OnLocaleReset onLocaleReset(
    YRTLocaleResetDelegate handler);
OnLocaleResetError onLocaleResetError(
    YRTLocaleResetDelegate handler);

OnLocaleReceived onLocaleReceived(
    YRTLocaleDelegate handler);
OnLocaleError onLocaleError(
    YRTLocaleDelegate handler);

} // namespace ios
} // namespace i18n
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTI18nManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>&)native;

- (std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>)nativeI18nManager;
- (std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>)native;

@end
