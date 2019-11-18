#import <YandexMapKit/YMKTileProvider.h>

#import <yandex/maps/mapkit/tiles/tile_provider.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace tiles {
namespace ios {

class TileProviderBinding : public ::yandex::maps::mapkit::tiles::TileProvider {
public:
    explicit TileProviderBinding(
        id<YMKTileProvider> platformListener);

    virtual std::shared_ptr<::yandex::maps::mapkit::RawTile> load(
        const ::yandex::maps::mapkit::TileId& tileId,
        const ::yandex::maps::mapkit::Version& version,
        const std::string& etag) const override;

    id<YMKTileProvider> platformReference() const { return platformListener_; }

private:
    __weak id<YMKTileProvider> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider>, id<YMKTileProvider>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider> from(
        id<YMKTileProvider> platformTileProvider);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider> from(
        PlatformType platformTileProvider)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider>, id<YMKTileProvider>>::from(
            platformTileProvider);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider>> {
    static id<YMKTileProvider> from(
        const std::shared_ptr<::yandex::maps::mapkit::tiles::TileProvider>& nativeTileProvider);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
