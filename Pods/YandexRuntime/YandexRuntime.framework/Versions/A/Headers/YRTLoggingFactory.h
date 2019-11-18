#import <Foundation/Foundation.h>

@class YRTLogging;

@interface YRTLoggingFactory : NSObject

/// @cond EXCLUDE
+ (nonnull YRTLogging *)getLogging;
/// @endcond


@end
