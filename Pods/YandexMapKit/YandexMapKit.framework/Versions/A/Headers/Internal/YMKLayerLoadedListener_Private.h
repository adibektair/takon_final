#import <YandexMapKit/YMKLayerLoadedListener.h>

#import <yandex/maps/mapkit/layers/layer_loaded_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace layers {
namespace ios {

class LayerLoadedListenerBinding : public ::yandex::maps::mapkit::layers::LayerLoadedListener {
public:
    explicit LayerLoadedListenerBinding(
        id<YMKLayerLoadedListener> platformListener);

    virtual void onLayerLoaded() override;

    id<YMKLayerLoadedListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKLayerLoadedListener> platformListener_;
};

} // namespace ios
} // namespace layers
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener>, id<YMKLayerLoadedListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener> from(
        id<YMKLayerLoadedListener> platformLayerLoadedListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener> from(
        PlatformType platformLayerLoadedListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener>, id<YMKLayerLoadedListener>>::from(
            platformLayerLoadedListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener>> {
    static id<YMKLayerLoadedListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::layers::LayerLoadedListener>& nativeLayerLoadedListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
