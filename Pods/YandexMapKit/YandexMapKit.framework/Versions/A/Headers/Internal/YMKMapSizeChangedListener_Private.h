#import <YandexMapKit/YMKMapSizeChangedListener.h>

#import <yandex/maps/mapkit/map/size_changed_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class SizeChangedListenerBinding : public ::yandex::maps::mapkit::map::SizeChangedListener {
public:
    explicit SizeChangedListenerBinding(
        id<YMKMapSizeChangedListener> platformListener);

    virtual void onMapWindowSizeChanged(
        ::yandex::maps::mapkit::map::MapWindow* mapWindow,
        int newWidth,
        int newHeight) override;

    id<YMKMapSizeChangedListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapSizeChangedListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener>, id<YMKMapSizeChangedListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener> from(
        id<YMKMapSizeChangedListener> platformSizeChangedListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener> from(
        PlatformType platformSizeChangedListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener>, id<YMKMapSizeChangedListener>>::from(
            platformSizeChangedListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener>> {
    static id<YMKMapSizeChangedListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::SizeChangedListener>& nativeSizeChangedListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
