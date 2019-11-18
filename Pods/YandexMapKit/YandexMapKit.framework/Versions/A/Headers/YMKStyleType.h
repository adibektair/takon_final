#import <Foundation/Foundation.h>

/// @cond EXCLUDE
/**
 * The style of the displayed map.
 */
typedef NS_ENUM(NSUInteger, YMKStyleType) {

    /**
     * Default style for mobile maps applications.
     */
    YMKStyleTypeVMap2,

    /**
     * Style for Yandex.Navigator.
     */
    YMKStyleTypeVNav2,

    /**
     * Same as VMap2, but in vec3 format.
     */
    YMKStyleTypeVMap3
};
/// @endcond

