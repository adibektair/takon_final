#import <YandexMapKit/YMKAttribution.h>
#import <YandexMapKit/YMKRoadEventsRoadEvents.h>
#import <YandexMapKit/YMKRoadEventsTimePeriod.h>
#import <YandexMapKit/YMKTime.h>

/// @cond EXCLUDE
@interface YMKRoadEventsRoadEventMetadata : NSObject

@property (nonatomic, readonly, nonnull) NSString *eventId;

/**
 * Point id obtained from server.
 *
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSString *description;

/**
 * FIXME This field must be required in idl and optional in protobuf.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *types;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKRoadEventsTimePeriod *timePeriod;

@property (nonatomic, readonly, nonnull) YMKTime *modificationTime;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) NSNumber *commentsCount;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKAttributionAuthor *author;


+ (nonnull YMKRoadEventsRoadEventMetadata *)roadEventMetadataWithEventId:(nonnull NSString *)eventId
                                                             description:(nullable NSString *)description
                                                                   types:(nonnull NSArray<NSNumber *> *)types
                                                              timePeriod:(nullable YMKRoadEventsTimePeriod *)timePeriod
                                                        modificationTime:(nonnull YMKTime *)modificationTime
                                                           commentsCount:(nullable NSNumber *)commentsCount
                                                                  author:(nullable YMKAttributionAuthor *)author;


@end
/// @endcond

