#import <YandexMapKit/YMKTileId.h>

#import <yandex/maps/mapkit/tile_id.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::TileId, YMKTileId, void> {
    static ::yandex::maps::mapkit::TileId from(
        YMKTileId* platformTileId);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::TileId, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKTileId*>::value>::type> {
    static ::yandex::maps::mapkit::TileId from(
        PlatformType platformTileId)
    {
        return ToNative<::yandex::maps::mapkit::TileId, YMKTileId>::from(
            platformTileId);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::TileId> {
    static YMKTileId* from(
        const ::yandex::maps::mapkit::TileId& tileId);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
