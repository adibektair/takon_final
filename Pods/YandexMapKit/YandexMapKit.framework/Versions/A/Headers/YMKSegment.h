#import <YandexMapKit/YMKPoint.h>

/**
 * A line between two points.
 */
@interface YMKSegment : NSObject

/**
 * Starting point of the segment.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *startPoint;

/**
 * End point of the segment.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *endPoint;


+ (nonnull YMKSegment *)segmentWithStartPoint:(nonnull YMKPoint *)startPoint
                                     endPoint:(nonnull YMKPoint *)endPoint;


@end

