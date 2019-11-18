#import <Foundation/Foundation.h>

/**
 * The way images repeat.
 */
typedef NS_ENUM(NSUInteger, YMKPatternRepeatMode) {

    /**
     * Repeat image horizontally and vertically
     */
    YMKPatternRepeatModeRepeat,

    /**
     * Repeat image horizontally and vertically, alternating mirror images
     * so that adjacent images always seam.
     */
    YMKPatternRepeatModeMirror
};

