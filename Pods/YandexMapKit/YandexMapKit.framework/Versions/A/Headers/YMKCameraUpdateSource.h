#import <Foundation/Foundation.h>

/**
 * The source of the camera update.
 */
typedef NS_ENUM(NSUInteger, YMKCameraUpdateSource) {

    /**
     * User manipulation, for example: zoom, scroll, rotate, fling.
     */
    YMKCameraUpdateSourceGestures,

    /**
     * Application, by calling the map::move method.
     */
    YMKCameraUpdateSourceApplication
};

