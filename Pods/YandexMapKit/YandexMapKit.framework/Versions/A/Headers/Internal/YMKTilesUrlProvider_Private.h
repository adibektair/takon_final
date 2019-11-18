#import <YandexMapKit/YMKTilesUrlProvider.h>

#import <yandex/maps/mapkit/tiles/url_provider.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace tiles {
namespace ios {

class UrlProviderBinding : public ::yandex::maps::mapkit::tiles::UrlProvider {
public:
    explicit UrlProviderBinding(
        id<YMKTilesUrlProvider> platformListener);

    virtual std::string formatUrl(
        const ::yandex::maps::mapkit::TileId& tileId,
        const ::yandex::maps::mapkit::Version& version) const override;

    id<YMKTilesUrlProvider> platformReference() const { return platformListener_; }

private:
    __weak id<YMKTilesUrlProvider> platformListener_;
};

} // namespace ios
} // namespace tiles
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider>, id<YMKTilesUrlProvider>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider> from(
        id<YMKTilesUrlProvider> platformUrlProvider);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider> from(
        PlatformType platformUrlProvider)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider>, id<YMKTilesUrlProvider>>::from(
            platformUrlProvider);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider>> {
    static id<YMKTilesUrlProvider> from(
        const std::shared_ptr<::yandex::maps::mapkit::tiles::UrlProvider>& nativeUrlProvider);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
