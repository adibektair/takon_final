#import <YandexMapKit/YMKUserLocationTapListener.h>

#import <yandex/maps/mapkit/user_location/user_location.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace user_location {
namespace ios {

class UserLocationTapListenerBinding : public ::yandex::maps::mapkit::user_location::UserLocationTapListener {
public:
    explicit UserLocationTapListenerBinding(
        id<YMKUserLocationTapListener> platformListener);

    virtual void onUserLocationObjectTap(
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    id<YMKUserLocationTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKUserLocationTapListener> platformListener_;
};

} // namespace ios
} // namespace user_location
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, id<YMKUserLocationTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener> from(
        id<YMKUserLocationTapListener> platformUserLocationTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener> from(
        PlatformType platformUserLocationTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, id<YMKUserLocationTapListener>>::from(
            platformUserLocationTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>> {
    static id<YMKUserLocationTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>& nativeUserLocationTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
