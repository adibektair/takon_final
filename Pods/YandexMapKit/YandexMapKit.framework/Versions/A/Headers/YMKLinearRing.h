#import <YandexMapKit/YMKPoint.h>

/**
 * A sequence of four or more vertices, with all points along the
 * linearly-interpolated curves (line segments) between each pair of
 * consecutive vertices. A ring must have either 0, 4 or more points.
 * The first and last points of the ring must be in the same position.
 * The ring must not intersect with itself.
 */
@interface YMKLinearRing : NSObject

/**
 * The list of points to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPoint *> *points;


+ (nonnull YMKLinearRing *)linearRingWithPoints:(nonnull NSArray<YMKPoint *> *)points;


@end

