#import <YandexMapKit/YMKLinearRing.h>

/**
 * A polygon with one or more polygons in it. The exterior and interior
 * areas are specified using LinearRing.
 */
@interface YMKPolygon : NSObject

/**
 * The ring specifying the area.
 */
@property (nonatomic, readonly, nonnull) YMKLinearRing *outerRing;

/**
 * The list of rings in the specified area.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKLinearRing *> *innerRings;


+ (nonnull YMKPolygon *)polygonWithOuterRing:(nonnull YMKLinearRing *)outerRing
                                  innerRings:(nonnull NSArray<YMKLinearRing *> *)innerRings;


@end

