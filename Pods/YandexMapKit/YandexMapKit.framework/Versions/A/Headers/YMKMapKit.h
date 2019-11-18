#import <YandexMapKit/YMKCoverage.h>
#import <YandexMapKit/YMKDummyLocationManager.h>
#import <YandexMapKit/YMKIndoorLayer.h>
#import <YandexMapKit/YMKLocationManager.h>
#import <YandexMapKit/YMKLocationSimulator.h>
#import <YandexMapKit/YMKMapWindow.h>
#import <YandexMapKit/YMKOfflineCacheManager.h>
#import <YandexMapKit/YMKPersonalizedPoiLayer.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKRoadEventsManager.h>
#import <YandexMapKit/YMKStorageManager.h>
#import <YandexMapKit/YMKStyleType.h>
#import <YandexMapKit/YMKTrafficLayer.h>
#import <YandexMapKit/YMKUiExperimentsManager.h>
#import <YandexMapKit/YMKUserLocationLayer.h>

#import <YandexRuntime/YRTAccount.h>
#import <YandexRuntime/YRTMiidManager.h>

@class YRTView;

/**
 * Provides access to all services in the SDK.
 *
 * Initialize the MapKit factory before using this class.
 *
 * Note: MapKit holds listener/delegate objects by weak references. You
 * need to have strong references to them somewhere in the client code.
 */
@interface YMKMapKit : NSObject

/// @cond EXCLUDE
/**
 * Sets user-specific parameters for MapKit.
 *
 * @param uuid Refer to the Yandex.Metrica documentation for information
 * about what this is and how to get one.
 * @param deviceId Device ID.
 */
- (void)setMetricaIdsWithUuid:(nonnull NSString *)uuid
                     deviceId:(nonnull NSString *)deviceId;
/// @endcond


/// @cond EXCLUDE
/**
 * Sets the key for API access.
 *
 * @param key Key issued in the Developer Dashboard.
 */
- (void)setApiKeyWithKey:(nonnull NSString *)key;
/// @endcond


/// @cond EXCLUDE
/**
 * Sets the account that is used by services.
 *
 * Remark:
 * @param account has optional type, it may be uninitialized.
 */
- (void)setAccount:(nullable id<YRTAccount>)account;
/// @endcond


/// @cond EXCLUDE
- (void)setScaleFactorWithScaleFactor:(float)scaleFactor;
/// @endcond


/// @cond EXCLUDE
- (void)setStyleTypeWithStyleType:(YMKStyleType)styleType;
/// @endcond


/**
 * Notifies MapKit when the application resumes the foreground state.
 */
- (void)onStart;


/**
 * Notifies MapKit when the application pauses and goes to the
 * background.
 */
- (void)onStop;


/// @cond EXCLUDE
/**
 * Returns the manager that uniquely identifies the installed app.
 */
@property (nonatomic, readonly, nonnull) YRTMiidManager *miidManager;
/// @endcond

/// @cond EXCLUDE
/**
 * Creates a manager that allows to check if the "feature" with a given
 * ID covers some specific point or area.
 */
- (nonnull YMKCoverage *)createCoverageWithCoverageId:(nonnull NSString *)coverageId;
/// @endcond


/// @cond EXCLUDE
/**
 * Returns a manager that allows to listen for experimental UI
 * parameters.
 */
@property (nonatomic, readonly, nonnull) YMKUiExperimentsManager *uiExperimentsManager;
/// @endcond

/**
 * Creates a manager that allows to listen for device location updates.
 */
- (nonnull YMKLocationManager *)createLocationManager;


/**
 * Creates a suspended LocationSimulator object with the given geometry.
 */
- (nonnull YMKLocationSimulator *)createLocationSimulatorWithGeometry:(nonnull YMKPolyline *)geometry;


/**
 * Creates a manager that functions as a location proxy.
 */
- (nonnull YMKDummyLocationManager *)createDummyLocationManager;


/// @cond EXCLUDE
/**
 * Creates a manager that only uses the Yandex LBS service.
 */
- (nonnull YMKLocationManager *)createLbsLocationManager;
/// @endcond


/// @cond EXCLUDE
/**
 * Creates an internal "window" object that is used to show the map.
 *
 * Do not call this method - it is for internal use only. To show the
 * map, please use the corresponding map "view" object.
 */
- (nonnull YMKMapWindow *)createMapWindowWithPlatformView:(nonnull YRTView *)platformView;
/// @endcond


/// @cond EXCLUDE
/**
 * Creates an internal "window" object that is used to show the map with
 * a custom scale factor. The scale factor is equal to the number of
 * pixels per device-independent point.
 *
 * Do not call this method - it is for internal use only. To show the
 * map, please use the corresponding map "view" object.
 */
- (nonnull YMKMapWindow *)createMapWindowWithPlatformView:(nonnull YRTView *)platformView
                                        customScaleFactor:(float)customScaleFactor;
/// @endcond


/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Returns a manager that handles offline maps, search index and road
 * graph.
 */
@property (nonatomic, readonly, nonnull) YMKOfflineCacheManager *offlineCacheManager;

/**
 * Returns a manager that handles disk size and IO errors.
 */
@property (nonatomic, readonly, nonnull) YMKStorageManager *storageManager;

/// @cond EXCLUDE
/**
 * Creates the personalized POI layer.
 */
- (nonnull YMKPersonalizedPoiLayer *)createPersonalizedPoiLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;
/// @endcond


/**
 * Creates the traffic layer.
 */
- (nonnull YMKTrafficLayer *)createTrafficLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;


/// @cond EXCLUDE
/**
 * Creates the indoor layer.
 */
- (nonnull YMKIndoorLayer *)createIndoorLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;
/// @endcond


/// @cond EXCLUDE
/**
 * Creates a manager that allows to retrieve and add road events.
 */
- (nonnull YMKRoadEventsManager *)createRoadEventsManager;
/// @endcond


/**
 * Create layer with the user location icon.
 */
- (nonnull YMKUserLocationLayer *)createUserLocationLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;


/**
 * Returns the version of the MapKit bundle.
 */
@property (nonatomic, readonly, nonnull) NSString *version;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

