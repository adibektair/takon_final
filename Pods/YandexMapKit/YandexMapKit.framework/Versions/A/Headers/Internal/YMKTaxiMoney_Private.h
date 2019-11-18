#import <YandexMapKit/YMKTaxiMoney.h>

#import <yandex/maps/mapkit/money.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Money, YMKTaxiMoney, void> {
    static ::yandex::maps::mapkit::Money from(
        YMKTaxiMoney* platformMoney);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Money, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKTaxiMoney*>::value>::type> {
    static ::yandex::maps::mapkit::Money from(
        PlatformType platformMoney)
    {
        return ToNative<::yandex::maps::mapkit::Money, YMKTaxiMoney>::from(
            platformMoney);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Money> {
    static YMKTaxiMoney* from(
        const ::yandex::maps::mapkit::Money& money);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
