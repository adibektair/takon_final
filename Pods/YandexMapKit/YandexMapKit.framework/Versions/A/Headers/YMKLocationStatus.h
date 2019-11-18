#import <Foundation/Foundation.h>

/**
 * Defines if the location is available or not.
 */
typedef NS_ENUM(NSUInteger, YMKLocationStatus) {

    /**
     * Location is not available.
     */
    YMKLocationStatusNotAvailable,

    /**
     * Location is available.
     */
    YMKLocationStatusAvailable
};

