#import <YandexMapKit/YMKOfflineCacheRegionListener.h>

#import <yandex/maps/mapkit/offline_cache/region_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

class RegionListenerBinding : public ::yandex::maps::mapkit::offline_cache::RegionListener {
public:
    explicit RegionListenerBinding(
        id<YMKOfflineCacheRegionListener> platformListener);

    virtual void onRegionStateChanged(
        unsigned int regionId) override;

    virtual void onRegionProgress(
        unsigned int regionId) override;

    id<YMKOfflineCacheRegionListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKOfflineCacheRegionListener> platformListener_;
};

} // namespace ios
} // namespace offline_cache
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener>, id<YMKOfflineCacheRegionListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener> from(
        id<YMKOfflineCacheRegionListener> platformRegionListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener> from(
        PlatformType platformRegionListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener>, id<YMKOfflineCacheRegionListener>>::from(
            platformRegionListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener>> {
    static id<YMKOfflineCacheRegionListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListener>& nativeRegionListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
