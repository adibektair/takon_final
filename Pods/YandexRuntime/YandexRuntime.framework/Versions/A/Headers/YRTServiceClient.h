#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@protocol YRTServiceClient <NSObject>

/**
 * Note that calls might be handled in the Client in a different order
 * than they are handled in ServiceClient. "Calls from a remote process
 * are dispatched from a thread pool the platform maintains inside of
 * your own process".
 * https://developer.android.com/guide/components/aidl.html If you need
 * to keep the same order, you can see how naviprovider handles this
 * problem.
 */
- (BOOL)handleWithData:(nonnull NSData *)data;


- (nonnull NSString *)clientId;


@end
/// @endcond
