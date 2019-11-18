#import <YandexMapKit/YMKAtomLink.h>

/// @cond EXCLUDE
/**
 * Root feed element.
 */
@interface YMKAtomFeed : NSObject

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *nextpage;

@property (nonatomic, readonly, nonnull) NSArray<YMKAtomLink *> *links;


+ (nonnull YMKAtomFeed *)feedWithNextpage:(nullable NSString *)nextpage
                                    links:(nonnull NSArray<YMKAtomLink *> *)links;


@end
/// @endcond

