#import <YandexRuntime/YRTEventListener.h>

/// @cond EXCLUDE
typedef NS_ENUM(NSUInteger, YRTLoggingLevel) {

    YRTLoggingLevelNormal,

    YRTLoggingLevelVerbose
};
/// @endcond


/// @cond EXCLUDE
@interface YRTEventLogging : NSObject

/**
 * Subscribes to events with LoggingLevel.Normal
 */
- (void)subscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener;


/**
 * Subscribes to events with the given level
 */
- (void)subscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener
                             level:(YRTLoggingLevel)level;


- (void)unsubscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
/// @endcond

