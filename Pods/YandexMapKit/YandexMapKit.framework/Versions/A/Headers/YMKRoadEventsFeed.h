#import <YandexMapKit/YMKAtomFeed.h>
#import <YandexMapKit/YMKRoadEventsEntry.h>

/// @cond EXCLUDE
@interface YMKRoadEventsFeed : NSObject

@property (nonatomic, readonly, nonnull) YMKAtomFeed *atomFeed;

@property (nonatomic, readonly, nonnull) NSArray<YMKRoadEventsEntry *> *entries;


+ (nonnull YMKRoadEventsFeed *)feedWithAtomFeed:(nonnull YMKAtomFeed *)atomFeed
                                        entries:(nonnull NSArray<YMKRoadEventsEntry *> *)entries;


@end
/// @endcond

