#import <YandexMapKit/YMKIndoorLevel.h>

/// @cond EXCLUDE
@interface YMKIndoorPlan : NSObject

/**
 * List of all levels in indoor plan, from bottom to top.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKIndoorLevel *> *levels;

/**
 * Gets/sets active id.
 */
@property (nonatomic, nonnull) NSString *activeLevelId;

@end
/// @endcond

