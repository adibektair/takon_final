#import <Foundation/Foundation.h>

/**
 * The type of icon to use.
 */
typedef NS_ENUM(NSUInteger, YMKUserLocationIconType) {

    /**
     * Arrow icon.
     */
    YMKUserLocationIconTypeArrow,

    /**
     * Pin icon.
     */
    YMKUserLocationIconTypePin
};


/**
 * The type of anchor to use.
 */
typedef NS_ENUM(NSUInteger, YMKUserLocationAnchorType) {

    /**
     * Normal anchor.
     */
    YMKUserLocationAnchorTypeNormal,

    /**
     * Course anchor.
     */
    YMKUserLocationAnchorTypeCourse
};

