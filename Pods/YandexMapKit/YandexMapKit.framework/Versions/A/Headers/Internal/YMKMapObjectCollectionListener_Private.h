#import <YandexMapKit/YMKMapObjectCollectionListener.h>

#import <yandex/maps/mapkit/map/map_object_collection_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class MapObjectCollectionListenerBinding : public ::yandex::maps::mapkit::map::MapObjectCollectionListener {
public:
    explicit MapObjectCollectionListenerBinding(
        id<YMKMapObjectCollectionListener> platformListener);

    virtual void onMapObjectAdded(
        ::yandex::maps::mapkit::map::MapObject* mapObject) override;

    virtual void onMapObjectRemoved(
        ::yandex::maps::mapkit::map::MapObject* mapObject) override;

    virtual void onMapObjectUpdated(
        ::yandex::maps::mapkit::map::MapObject* mapObject) override;

    id<YMKMapObjectCollectionListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapObjectCollectionListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener>, id<YMKMapObjectCollectionListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener> from(
        id<YMKMapObjectCollectionListener> platformMapObjectCollectionListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener> from(
        PlatformType platformMapObjectCollectionListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener>, id<YMKMapObjectCollectionListener>>::from(
            platformMapObjectCollectionListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener>> {
    static id<YMKMapObjectCollectionListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::MapObjectCollectionListener>& nativeMapObjectCollectionListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
