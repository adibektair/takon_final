#import <YandexMapKit/YMKTrafficListener.h>

/**
 * The level of traffic.
 */
@interface YMKTrafficLevel : NSObject

/**
 * The color that represents traffic.
 */
@property (nonatomic, readonly) YMKTrafficColor color;

/**
 * Traffic level.
 */
@property (nonatomic, readonly) NSInteger level;


+ (nonnull YMKTrafficLevel *)trafficLevelWithColor:( YMKTrafficColor)color
                                             level:( NSInteger)level;


@end

