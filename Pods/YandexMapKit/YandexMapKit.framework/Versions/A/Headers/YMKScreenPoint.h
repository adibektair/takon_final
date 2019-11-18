#import <Foundation/Foundation.h>

/**
 * A point on the device screen.
 */
@interface YMKScreenPoint : NSObject

/**
 * The horizontal position of the point in pixels from the left screen
 * border.
 */
@property (nonatomic, readonly) float x;

/**
 * The vertical position of the point in pixels from the top screen
 * border.
 */
@property (nonatomic, readonly) float y;


+ (nonnull YMKScreenPoint *)screenPointWithX:( float)x
                                           y:( float)y;


@end

