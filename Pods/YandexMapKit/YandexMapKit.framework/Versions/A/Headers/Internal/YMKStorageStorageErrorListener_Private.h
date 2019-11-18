#import <YandexMapKit/YMKStorageStorageErrorListener.h>

#import <yandex/maps/mapkit/storage/storage_error_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace storage {
namespace ios {

class StorageErrorListenerBinding : public ::yandex::maps::mapkit::storage::StorageErrorListener {
public:
    explicit StorageErrorListenerBinding(
        id<YMKStorageStorageErrorListener> platformListener);

    virtual void onStorageError(
        ::yandex::maps::runtime::LocalError* error) override;

    id<YMKStorageStorageErrorListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKStorageStorageErrorListener> platformListener_;
};

} // namespace ios
} // namespace storage
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, id<YMKStorageStorageErrorListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener> from(
        id<YMKStorageStorageErrorListener> platformStorageErrorListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener> from(
        PlatformType platformStorageErrorListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, id<YMKStorageStorageErrorListener>>::from(
            platformStorageErrorListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>> {
    static id<YMKStorageStorageErrorListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>& nativeStorageErrorListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
