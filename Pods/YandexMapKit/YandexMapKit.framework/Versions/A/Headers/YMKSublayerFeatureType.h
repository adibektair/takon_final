#import <Foundation/Foundation.h>

/**
 * Describes the type of features stored in the sublayer.
 */
typedef NS_ENUM(NSUInteger, YMKSublayerFeatureType) {

    /**
     * Polygons, polylines and raster tiles.
     */
    YMKSublayerFeatureTypeGround,

    /**
     * 3D buildings and models.
     */
    YMKSublayerFeatureTypeModels,

    /**
     * Screen and flat placemarks (excluding selected).
     */
    YMKSublayerFeatureTypePlacemarks,

    /**
     * Labels for polylines and points.
     */
    YMKSublayerFeatureTypeLabels,

    /**
     * Selected placemarks.
     */
    YMKSublayerFeatureTypeSelectedPlacemarks
};

