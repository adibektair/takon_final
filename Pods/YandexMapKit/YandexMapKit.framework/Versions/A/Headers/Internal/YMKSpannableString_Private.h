#import <YandexMapKit/YMKSpannableString.h>

#import <yandex/maps/mapkit/spannable_string.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>



namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::SpannableString::Span, YMKSpannableStringSpan, void> {
    static ::yandex::maps::mapkit::SpannableString::Span from(
        YMKSpannableStringSpan* platformSpan);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::SpannableString::Span, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSpannableStringSpan*>::value>::type> {
    static ::yandex::maps::mapkit::SpannableString::Span from(
        PlatformType platformSpan)
    {
        return ToNative<::yandex::maps::mapkit::SpannableString::Span, YMKSpannableStringSpan>::from(
            platformSpan);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::SpannableString::Span> {
    static YMKSpannableStringSpan* from(
        const ::yandex::maps::mapkit::SpannableString::Span& span);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
