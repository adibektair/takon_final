#import <YandexMapKit/YMKMapInputListener.h>

#import <yandex/maps/mapkit/map/input_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class InputListenerBinding : public ::yandex::maps::mapkit::map::InputListener {
public:
    explicit InputListenerBinding(
        id<YMKMapInputListener> platformListener);

    virtual void onMapTap(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    virtual void onMapLongTap(
        ::yandex::maps::mapkit::map::Map* map,
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    id<YMKMapInputListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapInputListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InputListener>, id<YMKMapInputListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::InputListener> from(
        id<YMKMapInputListener> platformInputListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InputListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::InputListener> from(
        PlatformType platformInputListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::InputListener>, id<YMKMapInputListener>>::from(
            platformInputListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::InputListener>> {
    static id<YMKMapInputListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::InputListener>& nativeInputListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
