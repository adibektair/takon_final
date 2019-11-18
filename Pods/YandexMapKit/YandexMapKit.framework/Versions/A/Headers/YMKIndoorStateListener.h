#import <YandexMapKit/YMKIndoorPlan.h>

/// @cond EXCLUDE
@protocol YMKIndoorStateListener <NSObject>

/**
 * Notifies when user view focuses on a new plan (@plan is NonNull).
 *
 * @param activePlan is valid until onActivePlanLeft call.
 */
- (void)onActivePlanFocusedWithActivePlan:(nonnull YMKIndoorPlan *)activePlan;


/**
 * Notifies when user view leaves focus on a current active plan.
 */
- (void)onActivePlanLeft;


@end
/// @endcond
