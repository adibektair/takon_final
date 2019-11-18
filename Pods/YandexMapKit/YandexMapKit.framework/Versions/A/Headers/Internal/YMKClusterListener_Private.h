#import <YandexMapKit/YMKClusterListener.h>

#import <yandex/maps/mapkit/map/cluster_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class ClusterListenerBinding : public ::yandex::maps::mapkit::map::ClusterListener {
public:
    explicit ClusterListenerBinding(
        id<YMKClusterListener> platformListener);

    virtual void onClusterAdded(
        ::yandex::maps::mapkit::map::Cluster* cluster) override;

    id<YMKClusterListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKClusterListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener>, id<YMKClusterListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener> from(
        id<YMKClusterListener> platformClusterListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener> from(
        PlatformType platformClusterListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener>, id<YMKClusterListener>>::from(
            platformClusterListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener>> {
    static id<YMKClusterListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::ClusterListener>& nativeClusterListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
