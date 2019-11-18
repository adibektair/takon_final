#import <YandexMapKit/YMKScreenPoint.h>

/**
 * A rectangle on the device screen.
 */
@interface YMKScreenRect : NSObject

/**
 * The position of the top left corner of the rectangle.
 */
@property (nonatomic, readonly, nonnull) YMKScreenPoint *topLeft;

/**
 * The position of the bottom right corner of the rectangle.
 */
@property (nonatomic, readonly, nonnull) YMKScreenPoint *bottomRight;


+ (nonnull YMKScreenRect *)screenRectWithTopLeft:(nonnull YMKScreenPoint *)topLeft
                                     bottomRight:(nonnull YMKScreenPoint *)bottomRight;


@end

