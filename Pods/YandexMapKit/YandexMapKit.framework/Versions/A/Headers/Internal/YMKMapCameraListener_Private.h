#import <YandexMapKit/YMKMapCameraListener.h>

#import <yandex/maps/mapkit/map/camera_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class CameraListenerBinding : public ::yandex::maps::mapkit::map::CameraListener {
public:
    explicit CameraListenerBinding(
        id<YMKMapCameraListener> platformListener);

    virtual void onCameraPositionChanged(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::map::CameraPosition& cameraPosition,
        ::yandex::maps::mapkit::map::CameraUpdateSource cameraUpdateSource,
        bool finished) override;

    id<YMKMapCameraListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapCameraListener> platformListener_;
};

} // namespace ios
} // namespace map
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::CameraListener>, id<YMKMapCameraListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::CameraListener> from(
        id<YMKMapCameraListener> platformCameraListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::CameraListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::CameraListener> from(
        PlatformType platformCameraListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::CameraListener>, id<YMKMapCameraListener>>::from(
            platformCameraListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::CameraListener>> {
    static id<YMKMapCameraListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::CameraListener>& nativeCameraListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
