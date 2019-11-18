#import <Foundation/Foundation.h>

/**
 * The type of map displayed.
 */
typedef NS_ENUM(NSUInteger, YMKMapType) {

    /**
     * Do not use any of the predefined maps.
     */
    YMKMapTypeNone,

    /**
     * Raster map.
     */
    YMKMapTypeMap,

    /// @cond EXCLUDE
    /**
     * Default satellite map.
     */
    YMKMapTypeSatellite,
    /// @endcond

    /// @cond EXCLUDE
    /**
     * Satellite map with roads, buildings and labels.
     */
    YMKMapTypeHybrid,
    /// @endcond

    /**
     * Vector map.
     */
    YMKMapTypeVectorMap
};

