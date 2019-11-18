#import <YandexMapKit/YMKOfflineCacheManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/offline_cache/offline_cache_manager.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

OfflineCacheManager::OnClearCompleted onClearCompleted(
    YMKOfflineCacheManagerClearCallback handler);

OfflineCacheManager::OnSizeComputed onSizeComputed(
    YMKOfflineCacheManagerSizeCallback handler);

OfflineCacheManager::OnPathReceived onPathReceived(
    YMKOfflineCacheManagerPathGetterListener handler);

class ErrorListenerBinding : public ::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener {
public:
    explicit ErrorListenerBinding(
        id<YMKOfflineCacheManagerErrorListener> platformListener);

    virtual void onError(
        ::yandex::maps::runtime::Error* error) override;

    virtual void onRegionError(
        ::yandex::maps::runtime::Error* error,
        unsigned int regionId) override;

    id<YMKOfflineCacheManagerErrorListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKOfflineCacheManagerErrorListener> platformListener_;
};

} // namespace ios
} // namespace offline_cache
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKOfflineCacheManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>)nativeOfflineCacheManager;
- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>)native;

@end

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener>, id<YMKOfflineCacheManagerErrorListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener> from(
        id<YMKOfflineCacheManagerErrorListener> platformErrorListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener> from(
        PlatformType platformErrorListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener>, id<YMKOfflineCacheManagerErrorListener>>::from(
            platformErrorListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener>> {
    static id<YMKOfflineCacheManagerErrorListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager::ErrorListener>& nativeErrorListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
