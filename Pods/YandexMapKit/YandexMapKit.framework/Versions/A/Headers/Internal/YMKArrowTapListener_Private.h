#import <YandexMapKit/YMKArrowTapListener.h>

#import <yandex/maps/mapkit/map/arrow_tap_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class ArrowTapListenerBinding : public ::yandex::maps::mapkit::map::ArrowTapListener {
public:
    explicit ArrowTapListenerBinding(
        id<YMKArrowTapListener> platformListener);

    virtual void onArrowTap(
        unsigned int index) override;

    id<YMKArrowTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKArrowTapListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener>, id<YMKArrowTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener> from(
        id<YMKArrowTapListener> platformArrowTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener> from(
        PlatformType platformArrowTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener>, id<YMKArrowTapListener>>::from(
            platformArrowTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener>> {
    static id<YMKArrowTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::ArrowTapListener>& nativeArrowTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
