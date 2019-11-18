#import <YandexMapKit/YMKLocalizedValue.h>

#import <yandex/maps/mapkit/localized_value.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::LocalizedValue, YMKLocalizedValue, void> {
    static ::yandex::maps::mapkit::LocalizedValue from(
        YMKLocalizedValue* platformLocalizedValue);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::LocalizedValue, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKLocalizedValue*>::value>::type> {
    static ::yandex::maps::mapkit::LocalizedValue from(
        PlatformType platformLocalizedValue)
    {
        return ToNative<::yandex::maps::mapkit::LocalizedValue, YMKLocalizedValue>::from(
            platformLocalizedValue);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::LocalizedValue> {
    static YMKLocalizedValue* from(
        const ::yandex::maps::mapkit::LocalizedValue& localizedValue);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
