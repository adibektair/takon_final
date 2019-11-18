#import <Foundation/Foundation.h>

/// @cond EXCLUDE
/**
 * Save, edit and delete links in the feed.
 */
@interface YMKAtomLink : NSObject

@property (nonatomic, readonly, nonnull) NSString *href;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *rel;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *type;


+ (nonnull YMKAtomLink *)linkWithHref:(nonnull NSString *)href
                                  rel:(nullable NSString *)rel
                                 type:(nullable NSString *)type;


@end
/// @endcond

