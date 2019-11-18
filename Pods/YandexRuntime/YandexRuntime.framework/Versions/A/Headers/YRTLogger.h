#import <Foundation/Foundation.h>

@interface YRTLogger : NSObject

/// @cond EXCLUDE
+ (void)errorWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)warnWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)infoWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)debugWithStr:(nonnull NSString *)str;
/// @endcond


@end
