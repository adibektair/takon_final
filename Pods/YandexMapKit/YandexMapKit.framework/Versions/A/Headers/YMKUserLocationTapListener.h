#import <YandexMapKit/YMKPoint.h>

/**
 * Triggered by a tap on the user location icon.
 */
@protocol YMKUserLocationTapListener <NSObject>

/**
 * Called when the user taps a location object.
 */
- (void)onUserLocationObjectTapWithPoint:(nonnull YMKPoint *)point;


@end
