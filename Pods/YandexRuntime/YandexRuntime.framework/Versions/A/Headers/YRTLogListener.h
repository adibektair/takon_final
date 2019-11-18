#import <YandexRuntime/YRTLogMessage.h>

/// @cond EXCLUDE
@protocol YRTLogListener <NSObject>

- (void)onMessageRecievedWithMessage:(nonnull YRTLogMessage *)message;


@end
/// @endcond
