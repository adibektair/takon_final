#import <YandexMapKit/YMKLayerOptions.h>

#import <yandex/maps/mapkit/layers/layer_options.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::layers::LayerOptions, YMKLayerOptions, void> {
    static ::yandex::maps::mapkit::layers::LayerOptions from(
        YMKLayerOptions* platformLayerOptions);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::layers::LayerOptions, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKLayerOptions*>::value>::type> {
    static ::yandex::maps::mapkit::layers::LayerOptions from(
        PlatformType platformLayerOptions)
    {
        return ToNative<::yandex::maps::mapkit::layers::LayerOptions, YMKLayerOptions>::from(
            platformLayerOptions);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::layers::LayerOptions> {
    static YMKLayerOptions* from(
        const ::yandex::maps::mapkit::layers::LayerOptions& layerOptions);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
