#import <YandexMapKit/YMKRoadEventsRoadEvents.h>

/**
 * Road event tap object meta information.
 */
@interface YMKTrafficRoadEventTapInfo : NSObject

/**
 * Road event identifier.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Road event description.
 */
@property (nonatomic, readonly, nonnull) NSString *descriptionText;

/**
 * Road event type. New road event types may be introduced, so clients
 * should be ready to process them as the 'OTHER' type or ignore them.
 */
@property (nonatomic, readonly) YMKRoadEventsEventType type;


+ (nonnull YMKTrafficRoadEventTapInfo *)roadEventTapInfoWithId:(nonnull NSString *)id
                                               descriptionText:(nonnull NSString *)descriptionText
                                                          type:( YMKRoadEventsEventType)type;


@end

