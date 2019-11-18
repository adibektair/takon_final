#import <YandexMapKit/YMKInertiaMoveListener.h>

#import <yandex/maps/mapkit/map/inertia_move_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class InertiaMoveListenerBinding : public ::yandex::maps::mapkit::map::InertiaMoveListener {
public:
    explicit InertiaMoveListenerBinding(
        id<YMKInertiaMoveListener> platformListener);

    virtual void onStart(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::map::CameraPosition& finishCameraPosition) override;

    virtual void onCancel(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::map::CameraPosition& cameraPosition) override;

    virtual void onFinish(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::map::CameraPosition& cameraPosition) override;

    id<YMKInertiaMoveListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKInertiaMoveListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener>, id<YMKInertiaMoveListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener> from(
        id<YMKInertiaMoveListener> platformInertiaMoveListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener> from(
        PlatformType platformInertiaMoveListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener>, id<YMKInertiaMoveListener>>::from(
            platformInertiaMoveListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener>> {
    static id<YMKInertiaMoveListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::InertiaMoveListener>& nativeInertiaMoveListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
