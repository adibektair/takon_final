#import <YandexMapKit/YMKAttribution.h>

#import <yandex/maps/mapkit/attribution.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Attribution, YMKAttribution, void> {
    static ::yandex::maps::mapkit::Attribution from(
        YMKAttribution* platformAttribution);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Attribution, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAttribution*>::value>::type> {
    static ::yandex::maps::mapkit::Attribution from(
        PlatformType platformAttribution)
    {
        return ToNative<::yandex::maps::mapkit::Attribution, YMKAttribution>::from(
            platformAttribution);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Attribution> {
    static YMKAttribution* from(
        const ::yandex::maps::mapkit::Attribution& attribution);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Attribution::Author, YMKAttributionAuthor, void> {
    static ::yandex::maps::mapkit::Attribution::Author from(
        YMKAttributionAuthor* platformAuthor);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Attribution::Author, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAttributionAuthor*>::value>::type> {
    static ::yandex::maps::mapkit::Attribution::Author from(
        PlatformType platformAuthor)
    {
        return ToNative<::yandex::maps::mapkit::Attribution::Author, YMKAttributionAuthor>::from(
            platformAuthor);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Attribution::Author> {
    static YMKAttributionAuthor* from(
        const ::yandex::maps::mapkit::Attribution::Author& author);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::Attribution::Link, YMKAttributionLink, void> {
    static ::yandex::maps::mapkit::Attribution::Link from(
        YMKAttributionLink* platformLink);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::Attribution::Link, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKAttributionLink*>::value>::type> {
    static ::yandex::maps::mapkit::Attribution::Link from(
        PlatformType platformLink)
    {
        return ToNative<::yandex::maps::mapkit::Attribution::Link, YMKAttributionLink>::from(
            platformLink);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::Attribution::Link> {
    static YMKAttributionLink* from(
        const ::yandex::maps::mapkit::Attribution::Link& link);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
