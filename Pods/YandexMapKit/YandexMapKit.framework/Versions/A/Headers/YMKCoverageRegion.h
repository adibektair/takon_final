#import <Foundation/Foundation.h>

/// @cond EXCLUDE
/**
 * Represents one region of layer coverage.
 */
@interface YMKCoverageRegion : NSObject

/**
 * Region ID.
 */
@property (nonatomic, readonly) NSInteger id;

/**
 * Minimum zoom level.
 */
@property (nonatomic, readonly) NSInteger zoomMin;

/**
 * Maximum zoom level.
 */
@property (nonatomic, readonly) NSInteger zoomMax;


+ (nonnull YMKCoverageRegion *)regionWithId:( NSInteger)id
                                    zoomMin:( NSInteger)zoomMin
                                    zoomMax:( NSInteger)zoomMax;


@end
/// @endcond

