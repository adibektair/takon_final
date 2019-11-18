#import <YandexMapKit/YMKOfflineMapRegionListUpdatesListener.h>

#import <yandex/maps/mapkit/offline_cache/region_list_updates_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

class RegionListUpdatesListenerBinding : public ::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener {
public:
    explicit RegionListUpdatesListenerBinding(
        id<YMKOfflineMapRegionListUpdatesListener> platformListener);

    virtual void onListUpdated() override;

    id<YMKOfflineMapRegionListUpdatesListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKOfflineMapRegionListUpdatesListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener>, id<YMKOfflineMapRegionListUpdatesListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener> from(
        id<YMKOfflineMapRegionListUpdatesListener> platformRegionListUpdatesListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener> from(
        PlatformType platformRegionListUpdatesListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener>, id<YMKOfflineMapRegionListUpdatesListener>>::from(
            platformRegionListUpdatesListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener>> {
    static id<YMKOfflineMapRegionListUpdatesListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionListUpdatesListener>& nativeRegionListUpdatesListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
