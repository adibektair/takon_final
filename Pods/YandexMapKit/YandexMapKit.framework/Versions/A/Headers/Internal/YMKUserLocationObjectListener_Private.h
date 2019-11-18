#import <YandexMapKit/YMKUserLocationObjectListener.h>

#import <yandex/maps/mapkit/user_location/user_location.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace user_location {
namespace ios {

class UserLocationObjectListenerBinding : public ::yandex::maps::mapkit::user_location::UserLocationObjectListener {
public:
    explicit UserLocationObjectListenerBinding(
        id<YMKUserLocationObjectListener> platformListener);

    virtual void onObjectAdded(
        ::yandex::maps::mapkit::user_location::UserLocationView* view) override;

    virtual void onObjectRemoved(
        ::yandex::maps::mapkit::user_location::UserLocationView* view) override;

    virtual void onObjectUpdated(
        ::yandex::maps::mapkit::user_location::UserLocationView* view,
        ::yandex::maps::mapkit::layers::ObjectEvent* event) override;

    id<YMKUserLocationObjectListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKUserLocationObjectListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, id<YMKUserLocationObjectListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener> from(
        id<YMKUserLocationObjectListener> platformUserLocationObjectListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener> from(
        PlatformType platformUserLocationObjectListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, id<YMKUserLocationObjectListener>>::from(
            platformUserLocationObjectListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>> {
    static id<YMKUserLocationObjectListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>& nativeUserLocationObjectListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
