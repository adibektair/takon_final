#import <Foundation/Foundation.h>

/**
 * URI that can be used for requests.
 */
@interface YMKUri : NSObject

/**
 * Gets URI.
 */
@property (nonatomic, readonly, nonnull) NSString *value;


+ (nonnull YMKUri *)uriWithValue:(nonnull NSString *)value;


@end

