#import <YandexMapKit/YMKPoint.h>

/**
 * A rectangular box around the object.
 */
@interface YMKBoundingBox : NSObject

/**
 * The coordinates of the southwest corner of the box.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *southWest;

/**
 * The coordinates of the northeast corner of the box.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *northEast;


+ (nonnull YMKBoundingBox *)boundingBoxWithSouthWest:(nonnull YMKPoint *)southWest
                                           northEast:(nonnull YMKPoint *)northEast;


@end

