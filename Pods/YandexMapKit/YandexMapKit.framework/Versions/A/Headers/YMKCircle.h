#import <YandexMapKit/YMKPoint.h>

/**
 * A circle around the specified point.
 */
@interface YMKCircle : NSObject

/**
 * The coordinates of the center of the circle.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *center;

/**
 * The radius of the circle in meters.
 */
@property (nonatomic, readonly) float radius;


+ (nonnull YMKCircle *)circleWithCenter:(nonnull YMKPoint *)center
                                 radius:( float)radius;


@end

