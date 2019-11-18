#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@protocol YRTEventListener <NSObject>

- (void)onEventWithEvent:(nonnull NSString *)event
                    data:(nonnull NSDictionary<NSString *, NSString *> *)data;


- (void)onValueWithName:(nonnull NSString *)name
                  value:(double)value;


@end
/// @endcond
