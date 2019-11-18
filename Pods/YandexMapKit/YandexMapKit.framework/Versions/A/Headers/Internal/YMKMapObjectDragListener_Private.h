#import <YandexMapKit/YMKMapObjectDragListener.h>

#import <yandex/maps/mapkit/map/map_object_drag_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class MapObjectDragListenerBinding : public ::yandex::maps::mapkit::map::MapObjectDragListener {
public:
    explicit MapObjectDragListenerBinding(
        id<YMKMapObjectDragListener> platformListener);

    virtual void onMapObjectDragStart(
        ::yandex::maps::mapkit::map::MapObject* mapObject) override;

    virtual void onMapObjectDrag(
        ::yandex::maps::mapkit::map::MapObject* mapObject,
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    virtual void onMapObjectDragEnd(
        ::yandex::maps::mapkit::map::MapObject* mapObject) override;

    id<YMKMapObjectDragListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapObjectDragListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener>, id<YMKMapObjectDragListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener> from(
        id<YMKMapObjectDragListener> platformMapObjectDragListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener> from(
        PlatformType platformMapObjectDragListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener>, id<YMKMapObjectDragListener>>::from(
            platformMapObjectDragListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener>> {
    static id<YMKMapObjectDragListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::MapObjectDragListener>& nativeMapObjectDragListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
