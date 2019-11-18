#import <YandexMapKit/YMKStorageManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/storage/storage_manager.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace storage {
namespace ios {

StorageManager::OnClearCompleted onClearCompleted(
    YMKStorageManagerClearCallback handler);

StorageManager::OnSizeComputed onSizeComputed(
    YMKStorageManagerSizeCallback handler);
StorageManager::OnSizeError onSizeError(
    YMKStorageManagerSizeCallback handler);

StorageManager::OnPathReceived onPathReceived(
    YMKStorageManagerPathGetterListener handler);
StorageManager::OnPathReceiveError onPathReceiveError(
    YMKStorageManagerPathGetterListener handler);

class StorageMoveListenerBinding : public ::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener {
public:
    explicit StorageMoveListenerBinding(
        id<YMKStorageManagerStorageMoveListener> platformListener);

    virtual void onMoveProgress(
        int percent) override;

    virtual void onMoveCompleted() override;

    virtual void onMoveError(
        ::yandex::maps::runtime::Error* error) override;

    id<YMKStorageManagerStorageMoveListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKStorageManagerStorageMoveListener> platformListener_;
};

} // namespace ios
} // namespace storage
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKStorageManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager>)nativeStorageManager;
- (std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager>)native;

@end

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener>, id<YMKStorageManagerStorageMoveListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener> from(
        id<YMKStorageManagerStorageMoveListener> platformStorageMoveListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener> from(
        PlatformType platformStorageMoveListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener>, id<YMKStorageManagerStorageMoveListener>>::from(
            platformStorageMoveListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener>> {
    static id<YMKStorageManagerStorageMoveListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::storage::StorageManager::StorageMoveListener>& nativeStorageMoveListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
