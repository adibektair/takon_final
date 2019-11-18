#import <YandexRuntime/YRTCanonicalUnit.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/i18n/i18n_manager.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, YRTCanonicalUnit, void> {
    static ::yandex::maps::runtime::i18n::CanonicalUnit from(
        YRTCanonicalUnit* platformCanonicalUnit);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTCanonicalUnit*>::value>::type> {
    static ::yandex::maps::runtime::i18n::CanonicalUnit from(
        PlatformType platformCanonicalUnit)
    {
        return ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, YRTCanonicalUnit>::from(
            platformCanonicalUnit);
    }
};

template <>
struct ToPlatform<::yandex::maps::runtime::i18n::CanonicalUnit> {
    static YRTCanonicalUnit* from(
        const ::yandex::maps::runtime::i18n::CanonicalUnit& canonicalUnit);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
