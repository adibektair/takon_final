#import <Foundation/Foundation.h>

/// @cond EXCLUDE
/**
 * Information about the author of the post in the feed.
 */
@interface YMKAtomAuthor : NSObject

@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *uri;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *email;


+ (nonnull YMKAtomAuthor *)authorWithName:(nonnull NSString *)name
                                      uri:(nullable NSString *)uri
                                    email:(nullable NSString *)email;


@end
/// @endcond

