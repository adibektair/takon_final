#import <YandexMapKit/YMKTrafficLevel.h>

/**
 * Listener to handle traffic information.
 */
@protocol YMKTrafficDelegate <NSObject>

/**
 * Triggered when traffic level changes.
 *
 * Remark:
 * @param trafficLevel has optional type, it may be uninitialized.
 */
- (void)onTrafficChangedWithTrafficLevel:(nullable YMKTrafficLevel *)trafficLevel;


/**
 * Triggered when traffic information is loading.
 */
- (void)onTrafficLoading;


/**
 * Triggered when traffic information expires.
 */
- (void)onTrafficExpired;


@end
