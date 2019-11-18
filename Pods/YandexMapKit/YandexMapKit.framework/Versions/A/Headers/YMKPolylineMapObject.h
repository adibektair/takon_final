#import <YandexMapKit/YMKMapObject.h>
#import <YandexMapKit/YMKPolyline.h>

#import <UIKit/UIKit.h>

/**
 * A polyline displayed on the map.
 */
@interface YMKPolylineMapObject : YMKMapObject

/**
 * Polyline geometry.
 */
@property (nonatomic, nonnull) YMKPolyline *geometry;

/**
 * Stroke color. Default: hexademical RGBA code 0x0066FFFF. Setting the
 * stroke color to any transparent color (i.e. RGBA code 0x00000000)
 * effectively disables the stroke.
 */
@property (nonatomic, nonnull) UIColor *strokeColor;

/**
 * Stroke width in units. Default: 5. The size of a unit is equal to the
 * size of a pixel at the current zoom with the camera position's tilt
 * at 0 and a scale factor of 1.
 */
@property (nonatomic) float strokeWidth;

/**
 * Outline color. Default: hexademical RGBA code 0x00000000. Setting the
 * color to any transparent color (i.e. RGBA code 0x00000000)
 * effectively disables the outline.
 */
@property (nonatomic, nonnull) UIColor *outlineColor;

/**
 * Outline width in units. Default: 0. The size of a unit is equal to
 * the size of a pixel at the current zoom when the camera position's
 * tilt is equal to 0 and the scale factor is equal to 1.
 */
@property (nonatomic) float outlineWidth;

/**
 * The object geometry can be interpreted in two different ways: 1) If
 * the object mode is 'geodesic', the object geometry is defined on a
 * sphere. 2) Otherwise, the object geometry is defined in projected
 * space. Default: false.
 */
@property (nonatomic, getter=isGeodesic) BOOL geodesic;

/**
 * Length of a dash in units. Default: 0 (dashing is turned off).
 */
@property (nonatomic) float dashLength;

/**
 * Length of the gap between two dashes in units. Default: 0 (dashing is
 * turned off).
 */
@property (nonatomic) float gapLength;

/**
 * Offset from the start of the polyline to the reference dash in units.
 * Default: 0.
 */
@property (nonatomic) float dashOffset;

@end

