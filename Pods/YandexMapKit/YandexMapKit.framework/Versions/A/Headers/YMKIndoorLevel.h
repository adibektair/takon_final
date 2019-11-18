#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YMKIndoorLevel : NSObject

/**
 * Universal identifier of the level.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Localized display name of the level.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * true if level is under ground
 */
@property (nonatomic, readonly) BOOL isUnderground;


+ (nonnull YMKIndoorLevel *)indoorLevelWithId:(nonnull NSString *)id
                                         name:(nonnull NSString *)name
                                isUnderground:( BOOL)isUnderground;


@end
/// @endcond

