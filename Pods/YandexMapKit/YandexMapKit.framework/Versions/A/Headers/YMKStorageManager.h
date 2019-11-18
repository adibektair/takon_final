#import <YandexMapKit/YMKStorageStorageErrorListener.h>

typedef void(^YMKStorageManagerClearCallback)(
    );


typedef void(^YMKStorageManagerSizeCallback)(
    NSNumber * _Nullable bytes,
    NSError * _Nullable error);


typedef void(^YMKStorageManagerPathGetterListener)(
    NSString * _Nullable path,
    NSError * _Nullable error);


@protocol YMKStorageManagerStorageMoveListener <NSObject>

/**
 * Called when the operation makes progress. The percent is the rate of
 * completion in the range of 0 to 100.
 */
- (void)onMoveProgressWithPercent:(NSInteger)percent;


/**
 * Called when the request is completed.
 */
- (void)onMoveCompleted;


/**
 * Called when an error occurs.
 */
- (void)onMoveErrorWithError:(nonnull NSError *)error;


@end

/**
 * Storage manager. This is a manager that controls temporary cache
 * storages (e.g. map tiles).
 */
@interface YMKStorageManager : NSObject

/**
 * Subscribes to storage events.
 */
- (void)addStorageErrorListenerWithErrorListener:(nonnull id<YMKStorageStorageErrorListener>)errorListener;


/**
 * Unsubscribes from storage events.
 */
- (void)removeStorageErrorListenerWithErrorListener:(nonnull id<YMKStorageStorageErrorListener>)errorListener;


/**
 * Computes storage size in bytes.
 */
- (void)computeSizeWithSizeCallback:(nonnull YMKStorageManagerSizeCallback)sizeCallback;


/**
 * Removes all data.
 */
- (void)clearWithClearCallback:(nonnull YMKStorageManagerClearCallback)clearCallback;


/**
 * Sets the maximum tile cache size to limit bytes. When the limit is
 * reached, old tiles are removed.
 */
- (void)setMaxTileStorageSizeWithLimit:(long long)limit;


/**
 * Resets the tile cache size limit.
 */
- (void)resetMaxTileStorageSize;


/**
 * Obtains the current storage size limit in bytes.
 */
- (void)maxTileStorageSizeWithSizeCallback:(nonnull YMKStorageManagerSizeCallback)sizeCallback;


/**
 * Provides the data path for storage files.
 */
- (void)requestPathWithPathGetterListener:(nonnull YMKStorageManagerPathGetterListener)pathGetterListener;


/**
 * Moves storage to the specified folder. This operation is
 * non-cancellable. If there is already a pending operation to set the
 * storage path, it throws an error (Android). If the application exits
 * before the operation is completed, it does not take effect, but
 * garbage will not be cleared.
 *
 * @param newPath New path to store data.
 * @param storageMoveListener It will be unsubscribed automatically when
 * the operation is completed or fails with an error.
 */
- (void)moveDataWithNewPath:(nonnull NSString *)newPath
        storageMoveListener:(nonnull id<YMKStorageManagerStorageMoveListener>)storageMoveListener;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

