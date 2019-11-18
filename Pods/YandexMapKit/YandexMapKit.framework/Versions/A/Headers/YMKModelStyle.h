#import <Foundation/Foundation.h>

/**
 * The style of the model bounding box.
 */
@interface YMKModelStyle : NSObject

/**
 * Maximum linear size (other sides are calculated by using original
 * model scales) of the model bounding box in units. The size of the
 * unit is equal to the size of a pixel when the camera position's tilt
 * is equal to 0 and the scale factor is equal to 1.
 */
@property (nonatomic, assign) float size;

+ (nonnull YMKModelStyle *)modelStyleWithSize:( float)size;


@end

