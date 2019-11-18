#import <YandexMapKit/YMKClusterTapListener.h>

#import <yandex/maps/mapkit/map/cluster_tap_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class ClusterTapListenerBinding : public ::yandex::maps::mapkit::map::ClusterTapListener {
public:
    explicit ClusterTapListenerBinding(
        id<YMKClusterTapListener> platformListener);

    virtual bool onClusterTap(
        ::yandex::maps::mapkit::map::Cluster* cluster) override;

    id<YMKClusterTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKClusterTapListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener>, id<YMKClusterTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener> from(
        id<YMKClusterTapListener> platformClusterTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener> from(
        PlatformType platformClusterTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener>, id<YMKClusterTapListener>>::from(
            platformClusterTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener>> {
    static id<YMKClusterTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::ClusterTapListener>& nativeClusterTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
