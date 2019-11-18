#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKXYPoint.h>

/**
 * Makes two conversions: world->XY and XY->world, where XY are tile
 * indexes. There are two main derived classes: spherical mercator
 * (google, osm) and wgs84 mercator (yandex).
 */
@protocol YMKProjection <NSObject>

/**
 * Converts the world coordinates to a flat world position.
 */
- (nonnull YMKXYPoint *)worldToXYWithGeoPoint:(nonnull YMKPoint *)geoPoint
                                         zoom:(NSInteger)zoom;


/**
 * Converts the flat world position to world coordinates.
 */
- (nonnull YMKPoint *)xyToWorldWithXyPoint:(nonnull YMKXYPoint *)xyPoint
                                      zoom:(NSInteger)zoom;


@end
