#import <YandexMapKit/YMKLocationManager.h>
#import <YandexMapKit/YMKLocationSimulatorListener.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKPolylinePosition.h>

/**
 * Simulates the device location.
 */
@interface YMKLocationSimulator : YMKLocationManager

/**
 * The polyline describing the location.
 */
@property (nonatomic, nonnull) YMKPolyline *geometry;

/**
 * The position of the polyline.
 */
@property (nonatomic, readonly, nonnull) YMKPolylinePosition *polylinePosition;

/**
 * Movement speed.
 */
@property (nonatomic) double speed;

/**
 * Subscribes to simulation events.
 */
- (void)subscribeForSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;


/**
 * Unsubscribes from simulation events.
 */
- (void)unsubscribeFromSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;


/**
 * True if simulator is not suspended.
 */
@property (nonatomic, readonly, getter=isActive) BOOL active;

@end

