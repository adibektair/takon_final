#import <YandexMapKit/YMKPoint.h>

/**
 * A polyline between a number of points. A polyline is drawn between
 * consecutive points.
 */
@interface YMKPolyline : NSObject

/**
 * The list of points to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPoint *> *points;


+ (nonnull YMKPolyline *)polylineWithPoints:(nonnull NSArray<YMKPoint *> *)points;


@end

