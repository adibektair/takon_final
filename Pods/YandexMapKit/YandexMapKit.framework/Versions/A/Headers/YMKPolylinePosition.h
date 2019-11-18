#import <Foundation/Foundation.h>

/**
 * The position on a polyline.
 */
@interface YMKPolylinePosition : NSObject

/**
 * Zero-based index of the polyline segment.
 */
@property (nonatomic, readonly) NSUInteger segmentIndex;

/**
 * Position in the specified segment. Possible values: from 0 to 1,
 * where 0 is the start of the segment and 1 is the end of it.
 */
@property (nonatomic, readonly) double segmentPosition;


+ (nonnull YMKPolylinePosition *)polylinePositionWithSegmentIndex:( NSUInteger)segmentIndex
                                                  segmentPosition:( double)segmentPosition;


@end

