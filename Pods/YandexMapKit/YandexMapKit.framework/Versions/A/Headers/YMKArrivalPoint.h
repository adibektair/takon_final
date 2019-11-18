#import <YandexMapKit/YMKDirection.h>
#import <YandexMapKit/YMKPoint.h>

/**
 * An arrival point for a place (the position to drive/walk to if you
 * want to visit the place). For example, named entrance into the
 * building.
 */
@interface YMKArrivalPoint : NSObject

/**
 * Optional name for an arrival point, e.g. 'exit 4' or 'main entrance'.
 *
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Arrival point position.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *point;

/**
 * Azimuth for the outside normal to the building.
 *
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKDirection *direction;


+ (nonnull YMKArrivalPoint *)arrivalPointWithName:(nullable NSString *)name
                                            point:(nonnull YMKPoint *)point
                                        direction:(nullable YMKDirection *)direction;


@end

