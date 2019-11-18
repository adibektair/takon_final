#import <YandexMapKit/YMKCircleMapObject.h>
#import <YandexMapKit/YMKPlacemarkMapObject.h>

/**
 * Use this interface to specify the appearance of the user location
 * icon elements.
 */
@interface YMKUserLocationView : NSObject

/**
 * Gets the location arrow map object.
 */
@property (nonatomic, readonly, nonnull) YMKPlacemarkMapObject *arrow;

/**
 * Gets the location pin map object.
 */
@property (nonatomic, readonly, nonnull) YMKPlacemarkMapObject *pin;

/**
 * Gets the GPS accuracy circle map object.
 */
@property (nonatomic, readonly, nonnull) YMKCircleMapObject *accuracyCircle;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

