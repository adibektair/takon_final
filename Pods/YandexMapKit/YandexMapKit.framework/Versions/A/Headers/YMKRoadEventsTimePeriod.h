#import <YandexMapKit/YMKTime.h>

/// @cond EXCLUDE
@interface YMKRoadEventsTimePeriod : NSObject

/**
 * Unix timestamps.
 */
@property (nonatomic, readonly, nonnull) YMKTime *begin;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKTime *end;


+ (nonnull YMKRoadEventsTimePeriod *)timePeriodWithBegin:(nonnull YMKTime *)begin
                                                     end:(nullable YMKTime *)end;


@end
/// @endcond

