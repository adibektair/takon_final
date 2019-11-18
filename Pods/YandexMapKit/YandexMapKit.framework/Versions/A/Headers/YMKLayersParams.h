#import <Foundation/Foundation.h>

/**
 * The list of layer parameters.
 */
@interface YMKLayersParams : NSObject

/**
 * A dictionary of parameters.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> *params;


+ (nonnull YMKLayersParams *)paramsWithParams:(nonnull NSDictionary<NSString *, NSString *> *)params;


@end

