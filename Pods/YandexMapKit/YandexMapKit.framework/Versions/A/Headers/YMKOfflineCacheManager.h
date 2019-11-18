#import <YandexMapKit/YMKOfflineCacheDataMoveListener.h>
#import <YandexMapKit/YMKOfflineCacheRegion.h>
#import <YandexMapKit/YMKOfflineCacheRegionListener.h>
#import <YandexMapKit/YMKOfflineCacheRegionState.h>
#import <YandexMapKit/YMKOfflineMapRegionListUpdatesListener.h>

typedef void(^YMKOfflineCacheManagerClearCallback)(
    );


typedef void(^YMKOfflineCacheManagerSizeCallback)(
    NSNumber * _Nullable size);


typedef void(^YMKOfflineCacheManagerPathGetterListener)(
    NSString * _Nonnull path);


@protocol YMKOfflineCacheManagerErrorListener <NSObject>

/**
 *
 * @param error Error has occurred in offline cache manager. Expected
 * error types: 1. RemoteError 2. LocalError
 */
- (void)onErrorWithError:(nonnull NSError *)error;


/**
 *
 * @param error Error has occurred in specific region. Expected error
 * types: 1. RemoteError 2. LocalError
 */
- (void)onRegionErrorWithError:(nonnull NSError *)error
                      regionId:(NSUInteger)regionId;


@end

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Offline cache manager.
 */
@interface YMKOfflineCacheManager : NSObject

/**
 * Copying a list of regions from memory. All changes of regions won't
 * affected on on the collection.
 */
- (nonnull NSArray<YMKOfflineCacheRegion *> *)regions;


/**
 * Indicates whether to allow downloading using cellular networks (3G,
 * LTE, etc.) Disallowed by default.
 */
- (void)allowUseCellularNetworkWithUseCellular:(BOOL)useCellular;


/**
 * Subscribe on update of region list
 */
- (void)addRegionListUpdatesListenerWithRegionListUpdatesListener:(nonnull id<YMKOfflineMapRegionListUpdatesListener>)regionListUpdatesListener;


/**
 * Unsubscribe from region list update
 */
- (void)removeRegionListUpdatesListenerWithRegionListUpdatesListener:(nonnull id<YMKOfflineMapRegionListUpdatesListener>)regionListUpdatesListener;


/**
 * Subscribe on errors
 */
- (void)addErrorListenerWithErrorListener:(nonnull id<YMKOfflineCacheManagerErrorListener>)errorListener;


/**
 * Unsubscribe from errors
 */
- (void)removeErrorListenerWithErrorListener:(nonnull id<YMKOfflineCacheManagerErrorListener>)errorListener;


/**
 * Subscribe on status events
 */
- (void)addRegionListenerWithRegionListener:(nonnull id<YMKOfflineCacheRegionListener>)regionListener;


/**
 * Unsubscribe from status events
 */
- (void)removeRegionListenerWithRegionListener:(nonnull id<YMKOfflineCacheRegionListener>)regionListener;


/**
 * Returns a list of cities.
 */
- (nonnull NSArray<NSString *> *)getCitiesWithRegionId:(NSUInteger)regionId;


/**
 * Current region state
 */
- (YMKOfflineCacheRegionState)getStateWithRegionId:(NSUInteger)regionId;


/**
 * Current region progress [0,1]. For downloaded files returns 1; If we
 * haven't start download yet, returns 0;
 */
- (float)getProgressWithRegionId:(NSUInteger)regionId;


/**
 * Start to download new offline cache for the region or update if
 * region has been downloaded
 */
- (void)startDownloadWithRegionId:(NSUInteger)regionId;


/**
 * Stop downloading of region
 */
- (void)stopDownloadWithRegionId:(NSUInteger)regionId;


/**
 * Pause downloading of region
 */
- (void)pauseDownloadWithRegionId:(NSUInteger)regionId;


/**
 * Drop region data from the device. If data is being downloaded then
 * downloading is cancelled.
 */
- (void)dropWithRegionId:(NSUInteger)regionId;


/**
 * Returns true if available disk space might not be enough for
 * installation of the region data.
 */
- (BOOL)mayBeOutOfAvailableSpaceWithRegionId:(NSUInteger)regionId;


/**
 * Returns true if region has files with legacy localized path. If
 * region in downloading state result may be incorrect.
 */
- (BOOL)isLegacyPathWithRegionId:(NSUInteger)regionId;


/**
 * Calculates the full cache size in bytes.
 */
- (void)computeCacheSizeWithSizeCallback:(nonnull YMKOfflineCacheManagerSizeCallback)sizeCallback;


/**
 * Provides the data path for offline cache files.
 */
- (void)requestPathWithPathGetterListener:(nonnull YMKOfflineCacheManagerPathGetterListener)pathGetterListener;


/**
 * Moves offline caches to the specified folder. This operation is
 * non-cancellable. If there is already a pending operation to set the
 * cache path, it throws an error (Android). If the application exits
 * before the operation is completed, it does not take effect, but
 * garbage will not be cleared.
 *
 * @param newPath New path to store data.
 * @param dataMoveListener It will be unsubscribed automatically when
 * the operation is completed or fails with an error.
 */
- (void)moveDataWithNewPath:(nonnull NSString *)newPath
           dataMoveListener:(nonnull id<YMKOfflineCacheDataMoveListener>)dataMoveListener;


/**
 * Sets a new path for caches. If the specified path contains an
 * existing cache, this cache will be used; otherwise, a new cache will
 * be initialized. This takes effect after the application is restarted.
 */
- (void)setCachePathWithPath:(nonnull NSString *)path;


/**
 * Enables autoupdating downloaded caches when they become outdated.
 */
- (void)enableAutoUpdateWithEnable:(BOOL)enable;


/**
 * Erases all data for downloads and regions and wipes the tile cache.
 * Forces reloading the list from the remote source
 */
- (void)clearWithClearCallback:(nonnull YMKOfflineCacheManagerClearCallback)clearCallback;


/// @cond EXCLUDE
/**
 * This method turns all to outated. Only for testing.
 */
- (void)simulateUpdate;
/// @endcond


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

