#import <YandexMapKit/YMKAtomEntry.h>
#import <YandexMapKit/YMKRoadEventsTextEntry.h>

/// @cond EXCLUDE
@interface YMKRoadEventsEntry : NSObject

@property (nonatomic, readonly, nonnull) YMKAtomEntry *atomEntry;

@property (nonatomic, readonly, nonnull) YMKRoadEventsTextEntry *content;


+ (nonnull YMKRoadEventsEntry *)entryWithAtomEntry:(nonnull YMKAtomEntry *)atomEntry
                                           content:(nonnull YMKRoadEventsTextEntry *)content;


@end
/// @endcond

