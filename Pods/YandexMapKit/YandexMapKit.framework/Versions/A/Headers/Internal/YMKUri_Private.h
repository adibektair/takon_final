#import <YandexMapKit/YMKUri.h>

#import <yandex/maps/mapkit/uri/uri_object_metadata.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::uri::Uri, YMKUri, void> {
    static ::yandex::maps::mapkit::uri::Uri from(
        YMKUri* platformUri);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::uri::Uri, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKUri*>::value>::type> {
    static ::yandex::maps::mapkit::uri::Uri from(
        PlatformType platformUri)
    {
        return ToNative<::yandex::maps::mapkit::uri::Uri, YMKUri>::from(
            platformUri);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::uri::Uri> {
    static YMKUri* from(
        const ::yandex::maps::mapkit::uri::Uri& uri);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
