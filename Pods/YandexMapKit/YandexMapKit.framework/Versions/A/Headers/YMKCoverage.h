#import <YandexMapKit/YMKCoverageIsCoveredSession.h>
#import <YandexMapKit/YMKCoverageRegionsSession.h>
#import <YandexMapKit/YMKLinearRing.h>
#import <YandexMapKit/YMKPoint.h>

/// @cond EXCLUDE
/**
 * Access to information about coverage of an area.
 */
@interface YMKCoverage : NSObject

/**
 * Return information about coverage of the specified point.
 *
 * @param point A point in the WGS-84 coordinate system.
 * @param zoom Zoom level.
 * @param isCoveredListener Listener that handles the coverage response.
 *
 * @return Request session.
 */
- (nonnull YMKCoverageIsCoveredSession *)isCoveredWithPoint:(nonnull YMKPoint *)point
                                                       zoom:(NSInteger)zoom
                                            responseHandler:(nonnull YMKCoverageIsCoveredSessionResponseHandler)responseHandler;


/**
 * Find regions that cover the specified point.
 *
 * @param point A point in the WGS-84 coordinate system.
 * @param zoom Zoom level.
 * @param regionsListener Listener that handles the coverage response.
 * Possible results: 1) Non-empty vector of regions covering the point,
 * if it is covered. 2) Empty vector, if the point isn't covered.
 *
 * @return Request session.
 */
- (nonnull YMKCoverageRegionsSession *)regionsWithPoint:(nonnull YMKPoint *)point
                                                   zoom:(NSInteger)zoom
                                        responseHandler:(nonnull YMKCoverageRegionsSessionResponseHandler)responseHandler;


/**
 * The area is considered covered by a "coverage" layer, if the area has
 * at least one common point with a coverage layer.
 *
 * @param area Area of interest.
 * @param zoom Zoom level.
 * @param isCoveredListener Listener that handles the coverage response.
 * Possible results: 1) Non-empty vector with regions covering the
 * point, if it is covered. 2) Empty vector, if the point isn't covered.
 *
 * @return Request session.
 */
- (nonnull YMKCoverageIsCoveredSession *)isCoveredWithArea:(nonnull YMKLinearRing *)area
                                                      zoom:(NSInteger)zoom
                                           responseHandler:(nonnull YMKCoverageIsCoveredSessionResponseHandler)responseHandler;


/**
 * Bind this method to a class that knows the visible map area. This
 * information is used for pre-fetching data. You can call this method
 * from any thread.
 *
 * @param area bounds of view area
 * @param zoom zoom
 */
- (void)setActiveAreaWithArea:(nonnull YMKLinearRing *)area
                         zoom:(NSInteger)zoom;


@end
/// @endcond

