#import <YandexMapKit/YMKMapLoadedListener.h>

#import <yandex/maps/mapkit/map/map_loaded_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class MapLoadedListenerBinding : public ::yandex::maps::mapkit::map::MapLoadedListener {
public:
    explicit MapLoadedListenerBinding(
        id<YMKMapLoadedListener> platformListener);

    virtual void onMapLoaded(
        const ::yandex::maps::mapkit::map::MapLoadStatistics& statistics) override;

    id<YMKMapLoadedListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapLoadedListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener>, id<YMKMapLoadedListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener> from(
        id<YMKMapLoadedListener> platformMapLoadedListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener> from(
        PlatformType platformMapLoadedListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener>, id<YMKMapLoadedListener>>::from(
            platformMapLoadedListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener>> {
    static id<YMKMapLoadedListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::MapLoadedListener>& nativeMapLoadedListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
