#import <Foundation/Foundation.h>

@class YRTEventLogging;

@interface YRTEventLoggingFactory : NSObject

/// @cond EXCLUDE
+ (nonnull YRTEventLogging *)getEventLogging;
/// @endcond


@end
