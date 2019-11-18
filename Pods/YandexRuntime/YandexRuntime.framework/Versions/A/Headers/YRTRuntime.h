#import <Foundation/Foundation.h>

typedef void(^YRTFailedAssertionListener)(
    NSString * _Nonnull file,
    NSInteger line,
    NSString * _Nonnull condition,
    NSString * _Nonnull message,
    NSArray<NSString *> * _Nonnull stack);


@interface YRTRuntime : NSObject

+ (nonnull NSString *)version;


/// @cond EXCLUDE
+ (void)setFailedAssertionListener:(nonnull YRTFailedAssertionListener)failedAssertionListener;
/// @endcond


@end
