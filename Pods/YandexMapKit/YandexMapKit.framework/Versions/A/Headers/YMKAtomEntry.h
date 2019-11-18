#import <YandexMapKit/YMKAtomAuthor.h>
#import <YandexMapKit/YMKAtomLink.h>
#import <YandexMapKit/YMKAttribution.h>

/// @cond EXCLUDE
/**
 * Common feed entry information.
 */
@interface YMKAtomEntry : NSObject

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *id;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *updateTime;

@property (nonatomic, readonly, nonnull) YMKAtomAuthor *author;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKAttribution *attribution;

@property (nonatomic, readonly, nonnull) NSArray<YMKAtomLink *> *links;


+ (nonnull YMKAtomEntry *)entryWithId:(nullable NSString *)id
                           updateTime:(nullable NSString *)updateTime
                               author:(nonnull YMKAtomAuthor *)author
                          attribution:(nullable YMKAttribution *)attribution
                                links:(nonnull NSArray<YMKAtomLink *> *)links;


@end
/// @endcond

