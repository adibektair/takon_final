#import <YandexMapKit/YMKMapObjectTapListener.h>

#import <yandex/maps/mapkit/map/map_object_tap_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class MapObjectTapListenerBinding : public ::yandex::maps::mapkit::map::MapObjectTapListener {
public:
    explicit MapObjectTapListenerBinding(
        id<YMKMapObjectTapListener> platformListener);

    virtual bool onMapObjectTap(
        ::yandex::maps::mapkit::map::MapObject* mapObject,
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    id<YMKMapObjectTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapObjectTapListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener>, id<YMKMapObjectTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener> from(
        id<YMKMapObjectTapListener> platformMapObjectTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener> from(
        PlatformType platformMapObjectTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener>, id<YMKMapObjectTapListener>>::from(
            platformMapObjectTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener>> {
    static id<YMKMapObjectTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::MapObjectTapListener>& nativeMapObjectTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
