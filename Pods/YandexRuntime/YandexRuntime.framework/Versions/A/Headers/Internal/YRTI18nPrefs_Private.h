#import <YandexRuntime/YRTI18nPrefs.h>

#import <yandex/maps/i18n/prefs.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::i18n::I18nPrefs, YRTI18nPrefs, void> {
    static ::yandex::maps::i18n::I18nPrefs from(
        YRTI18nPrefs* platformI18nPrefs);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::i18n::I18nPrefs, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTI18nPrefs*>::value>::type> {
    static ::yandex::maps::i18n::I18nPrefs from(
        PlatformType platformI18nPrefs)
    {
        return ToNative<::yandex::maps::i18n::I18nPrefs, YRTI18nPrefs>::from(
            platformI18nPrefs);
    }
};

template <>
struct ToPlatform<::yandex::maps::i18n::I18nPrefs> {
    static YRTI18nPrefs* from(
        const ::yandex::maps::i18n::I18nPrefs& i18nPrefs);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
