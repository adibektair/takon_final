#import <YandexMapKit/YMKAtomLink.h>

#import <yandex/maps/mapkit/atom/feed.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::atom::Link, YMKAtomLink, void> {
    static ::yandex::maps::mapkit::atom::Link from(
        YMKAtomLink* platformLink);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::atom::Link, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAtomLink*>::value>::type> {
    static ::yandex::maps::mapkit::atom::Link from(
        PlatformType platformLink)
    {
        return ToNative<::yandex::maps::mapkit::atom::Link, YMKAtomLink>::from(
            platformLink);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::atom::Link> {
    static YMKAtomLink* from(
        const ::yandex::maps::mapkit::atom::Link& link);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
