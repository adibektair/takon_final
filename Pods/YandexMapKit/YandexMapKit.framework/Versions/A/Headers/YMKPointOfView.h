#import <Foundation/Foundation.h>

/**
 * The point of view.
 */
typedef NS_ENUM(NSUInteger, YMKPointOfView) {

    /**
     * Point of View is centered on the screen.
     */
    YMKPointOfViewScreenCenter,

    /**
     * Point of View has an x-coordinate at the center of FocusRect and a
     * y-coordinate at the center of the screen.
     */
    YMKPointOfViewAdaptToFocusRectHorizontally
};

