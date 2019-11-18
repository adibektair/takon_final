#import <YandexMapKit/YMKArrowTapListener.h>
#import <YandexMapKit/YMKMapObject.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKPolylinePosition.h>
#import <YandexMapKit/YMKSubpolyline.h>

#import <UIKit/UIKit.h>

@class YMKArrow;

/**
 * A colored polyline object.
 */
@interface YMKColoredPolylineMapObject : YMKMapObject

/**
 * Provides the geometry.
 */
@property (nonatomic, nonnull) YMKPolyline *geometry;

/**
 * The stroke width in units. Default: 5. The size of a unit is equal to
 * the size of a pixel at the current zoom level when the camera
 * position's tilt is equal to 0 and the scale factor is equal to 1.
 */
@property (nonatomic) float strokeWidth;

/**
 * Maximum length (in units) of the gradient from one color to another.
 * Default: 0.
 */
@property (nonatomic) float gradientLength;

/**
 * The outline color. Default: white.
 */
@property (nonatomic, nonnull) UIColor *outlineColor;

/**
 * Width of the outline in units. Default: 2.
 */
@property (nonatomic) float outlineWidth;

/**
 * Enables the inner outline if true (a dark border along the edge of
 * the outline). Default: true.
 */
@property (nonatomic, getter=isInnerOutlineEnabled) BOOL innerOutlineEnabled;

/**
 * Maximum radius of a turn. Measured in units. Default: 10.
 */
@property (nonatomic) float turnRadius;

/**
 * Defines step of arc approximation. Smaller values make polyline
 * smoother. Measured in degrees. Default: 12.
 */
@property (nonatomic) float arcApproximationStep;

/**
 * Selects subpolyline by color.
 */
- (void)selectWithSelectionColor:(nonnull UIColor *)selectionColor
                     subpolyline:(nonnull YMKSubpolyline *)subpolyline;


/**
 * Hides the subpolyline, canceling any previous hides.
 */
- (void)hideWithSubpolyline:(nonnull YMKSubpolyline *)subpolyline;


/**
 * Hides multiple subpolylines, canceling any previous hides.
 */
- (void)hideWithSubpolylines:(nonnull NSArray<YMKSubpolyline *> *)subpolylines;


/**
 * Sets indexes of colors in palette for line segments. Weights are used
 * for generalization of colors.
 */
- (void)setColorsWithColors:(nonnull NSArray<NSNumber *> *)colors
                    weights:(nonnull NSArray<NSNumber *> *)weights;


/**
 * Sets indexes of colors in palette for line segments. All the weights
 * are equal to 1.
 */
- (void)setColorsWithColors:(nonnull NSArray<NSNumber *> *)colors;


/**
 * Sets color in RGBA mode for colorIndex. If the color is not provided
 * for some index, the default value 0xffffffff is used.
 */
- (void)setPaletteColorWithColorIndex:(NSUInteger)colorIndex
                                color:(nonnull UIColor *)color;


/**
 * Adds an arrow.
 *
 * @param position Coordinates of the center of the arrow.
 * @param length Overall length of the arrow (including the tip) in
 * units.
 * @param fillColor Color of the arrow.
 */
- (nonnull YMKArrow *)addArrowWithPosition:(nonnull YMKPolylinePosition *)position
                                    length:(float)length
                                 fillColor:(nonnull UIColor *)fillColor;


/**
 * Provides arrows.
 */
- (nonnull NSArray<YMKArrow *> *)arrows;


/**
 * Adds a tap listener for arrows.
 */
- (void)addArrowTapListenerWithTapListener:(nonnull id<YMKArrowTapListener>)tapListener;


/**
 * Removes the tap listener for arrows.
 */
- (void)removeArrowTapListenerWithTapListener:(nonnull id<YMKArrowTapListener>)tapListener;


@end

