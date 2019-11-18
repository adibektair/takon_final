#import <YandexMapKit/YMKGeometry.h>
#import <YandexMapKit/YMKVisibleRegion.h>

@interface YMKVisibleRegionUtils : NSObject

/**
 * Converts geometry to polygons.
 */
+ (nonnull YMKGeometry *)toPolygonWithVisibleRegion:(nonnull YMKVisibleRegion *)visibleRegion;


@end
