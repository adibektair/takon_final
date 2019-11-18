#import <Foundation/Foundation.h>

@class YRTServiceManager;

@interface YRTServiceManagerFactory : NSObject

/// @cond EXCLUDE
+ (nonnull YRTServiceManager *)getServiceManager;
/// @endcond


@end
