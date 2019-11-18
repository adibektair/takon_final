#import <YandexMapKit/YMKTrafficDelegate.h>

#import <yandex/maps/mapkit/traffic/traffic_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace traffic {
namespace ios {

class TrafficListenerBinding : public ::yandex::maps::mapkit::traffic::TrafficListener {
public:
    explicit TrafficListenerBinding(
        id<YMKTrafficDelegate> platformListener);

    virtual void onTrafficChanged(
        const std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficLevel>& trafficLevel) override;

    virtual void onTrafficLoading() override;

    virtual void onTrafficExpired() override;

    id<YMKTrafficDelegate> platformReference() const { return platformListener_; }

private:
    __weak id<YMKTrafficDelegate> platformListener_;
};

} // namespace ios
} // namespace traffic
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener>, id<YMKTrafficDelegate>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener> from(
        id<YMKTrafficDelegate> platformTrafficListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener> from(
        PlatformType platformTrafficListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener>, id<YMKTrafficDelegate>>::from(
            platformTrafficListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener>> {
    static id<YMKTrafficDelegate> from(
        const std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficListener>& nativeTrafficListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
