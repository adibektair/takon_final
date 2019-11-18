#import <YandexMapKit/YMKLayersGeoObjectTapListener.h>

#import <yandex/maps/mapkit/layers/geo_object_tap_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace layers {
namespace ios {

class GeoObjectTapListenerBinding : public ::yandex::maps::mapkit::layers::GeoObjectTapListener {
public:
    explicit GeoObjectTapListenerBinding(
        id<YMKLayersGeoObjectTapListener> platformListener);

    virtual bool onObjectTap(
        ::yandex::maps::mapkit::layers::GeoObjectTapEvent* event) override;

    id<YMKLayersGeoObjectTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKLayersGeoObjectTapListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener>, id<YMKLayersGeoObjectTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener> from(
        id<YMKLayersGeoObjectTapListener> platformGeoObjectTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener> from(
        PlatformType platformGeoObjectTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener>, id<YMKLayersGeoObjectTapListener>>::from(
            platformGeoObjectTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener>> {
    static id<YMKLayersGeoObjectTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::layers::GeoObjectTapListener>& nativeGeoObjectTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
