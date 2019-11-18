#import <YandexMapKit/YMKGlyphsGlyphUrlProvider.h>

#import <yandex/maps/mapkit/glyphs/glyph_url_provider.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace glyphs {
namespace ios {

class GlyphUrlProviderBinding : public ::yandex::maps::mapkit::glyphs::GlyphUrlProvider {
public:
    explicit GlyphUrlProviderBinding(
        id<YMKGlyphsGlyphUrlProvider> platformListener);

    virtual std::string formatUrl(
        const std::string& fontId,
        const ::yandex::maps::mapkit::glyphs::GlyphIdRange& range) const override;

    id<YMKGlyphsGlyphUrlProvider> platformReference() const { return platformListener_; }

private:
    __weak id<YMKGlyphsGlyphUrlProvider> platformListener_;
};

} // namespace ios
} // namespace glyphs
} // namespace mapkit
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider>, id<YMKGlyphsGlyphUrlProvider>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider> from(
        id<YMKGlyphsGlyphUrlProvider> platformGlyphUrlProvider);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider> from(
        PlatformType platformGlyphUrlProvider)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider>, id<YMKGlyphsGlyphUrlProvider>>::from(
            platformGlyphUrlProvider);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider>> {
    static id<YMKGlyphsGlyphUrlProvider> from(
        const std::shared_ptr<::yandex::maps::mapkit::glyphs::GlyphUrlProvider>& nativeGlyphUrlProvider);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
