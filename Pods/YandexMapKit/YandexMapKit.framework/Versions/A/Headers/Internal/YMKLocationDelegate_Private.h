#import <YandexMapKit/YMKLocationDelegate.h>

#import <yandex/maps/mapkit/location/location_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace location {
namespace ios {

class LocationListenerBinding : public ::yandex::maps::mapkit::location::LocationListener {
public:
    explicit LocationListenerBinding(
        id<YMKLocationDelegate> platformListener);

    virtual void onLocationUpdated(
        const ::yandex::maps::mapkit::location::Location& location) override;

    virtual void onLocationStatusUpdated(
        ::yandex::maps::mapkit::location::LocationStatus status) override;

    id<YMKLocationDelegate> platformReference() const { return platformListener_; }

private:
    __weak id<YMKLocationDelegate> platformListener_;
};

} // namespace ios
} // namespace location
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationListener>, id<YMKLocationDelegate>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::location::LocationListener> from(
        id<YMKLocationDelegate> platformLocationListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::location::LocationListener> from(
        PlatformType platformLocationListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationListener>, id<YMKLocationDelegate>>::from(
            platformLocationListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::location::LocationListener>> {
    static id<YMKLocationDelegate> from(
        const std::shared_ptr<::yandex::maps::mapkit::location::LocationListener>& nativeLocationListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
