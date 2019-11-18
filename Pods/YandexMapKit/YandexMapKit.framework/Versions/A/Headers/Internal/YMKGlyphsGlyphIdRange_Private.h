#import <YandexMapKit/YMKGlyphsGlyphIdRange.h>

#import <yandex/maps/mapkit/glyphs/glyph_id_range.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::glyphs::GlyphIdRange, YMKGlyphsGlyphIdRange, void> {
    static ::yandex::maps::mapkit::glyphs::GlyphIdRange from(
        YMKGlyphsGlyphIdRange* platformGlyphIdRange);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::glyphs::GlyphIdRange, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKGlyphsGlyphIdRange*>::value>::type> {
    static ::yandex::maps::mapkit::glyphs::GlyphIdRange from(
        PlatformType platformGlyphIdRange)
    {
        return ToNative<::yandex::maps::mapkit::glyphs::GlyphIdRange, YMKGlyphsGlyphIdRange>::from(
            platformGlyphIdRange);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::glyphs::GlyphIdRange> {
    static YMKGlyphsGlyphIdRange* from(
        const ::yandex::maps::mapkit::glyphs::GlyphIdRange& glyphIdRange);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
