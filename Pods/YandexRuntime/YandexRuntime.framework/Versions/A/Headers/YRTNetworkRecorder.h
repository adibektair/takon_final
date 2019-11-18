#import <YandexRuntime/YRTNetworkRecording.h>

/// @cond EXCLUDE
/**
 * Allows to record network requests.
 */
@interface YRTNetworkRecorder : NSObject

- (void)start;


- (void)stop;


- (void)dumpWithFilepath:(nonnull NSString *)filepath
  fileOperationsListener:(nonnull YRTFileOperationsListener)fileOperationsListener;


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

