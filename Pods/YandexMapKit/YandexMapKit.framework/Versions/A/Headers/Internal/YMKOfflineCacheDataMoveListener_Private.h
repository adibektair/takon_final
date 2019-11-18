#import <YandexMapKit/YMKOfflineCacheDataMoveListener.h>

#import <yandex/maps/mapkit/offline_cache/data_move_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

class DataMoveListenerBinding : public ::yandex::maps::mapkit::offline_cache::DataMoveListener {
public:
    explicit DataMoveListenerBinding(
        id<YMKOfflineCacheDataMoveListener> platformListener);

    virtual void onDataMoveProgress(
        int percent) override;

    virtual void onDataMoveCompleted() override;

    virtual void onDataMoveError(
        ::yandex::maps::runtime::Error* error) override;

    id<YMKOfflineCacheDataMoveListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKOfflineCacheDataMoveListener> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener>, id<YMKOfflineCacheDataMoveListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener> from(
        id<YMKOfflineCacheDataMoveListener> platformDataMoveListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener> from(
        PlatformType platformDataMoveListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener>, id<YMKOfflineCacheDataMoveListener>>::from(
            platformDataMoveListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener>> {
    static id<YMKOfflineCacheDataMoveListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::offline_cache::DataMoveListener>& nativeDataMoveListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
