#import <Foundation/Foundation.h>

/**
 * Specifies the way provided zoom focus point affects gestures.
 */
typedef NS_ENUM(NSUInteger, YMKZoomFocusPointMode) {

    /**
     * Only "double tap" (zoom in) and "tap with two fingers" (zoom out) use
     * provided zoom focus point. Other zoom gestures ignore it and continue
     * to use their source point for transformation.
     */
    YMKZoomFocusPointModeAffectsTapGestures,

    /**
     * All zoom gestures: pinch and stretch, tap and swipe, double tap, tap
     * with two fingers use provided zoom focus point and ignore their
     * source point. Note: Pinch and stretch gesture will also suppress
     * scroll and rotation when this mode is on.
     */
    YMKZoomFocusPointModeAffectsAllGestures
};

