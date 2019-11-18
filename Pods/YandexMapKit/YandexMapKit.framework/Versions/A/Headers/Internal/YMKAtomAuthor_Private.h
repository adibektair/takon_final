#import <YandexMapKit/YMKAtomAuthor.h>

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
struct ToNative<::yandex::maps::mapkit::atom::Author, YMKAtomAuthor, void> {
    static ::yandex::maps::mapkit::atom::Author from(
        YMKAtomAuthor* platformAuthor);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::atom::Author, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAtomAuthor*>::value>::type> {
    static ::yandex::maps::mapkit::atom::Author from(
        PlatformType platformAuthor)
    {
        return ToNative<::yandex::maps::mapkit::atom::Author, YMKAtomAuthor>::from(
            platformAuthor);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::atom::Author> {
    static YMKAtomAuthor* from(
        const ::yandex::maps::mapkit::atom::Author& author);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
