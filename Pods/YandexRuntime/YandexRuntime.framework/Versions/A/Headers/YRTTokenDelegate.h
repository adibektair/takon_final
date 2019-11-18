#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YRTTokenDelegate : NSObject

/**
 * Token was received.
 */
- (void)onTokenReceivedWithToken:(nonnull NSString *)token;


/**
 * XToken is not valid anymore. Password must be re-entered.
 *
 * @param data Contains platform-specific data for user input.
 */
- (void)onPasswordRequiredWithData:(nonnull id)data;


/**
 * An error occurred during OAuth token refresh (it might be a network
 * error or an invalid response from the authentication server).
 */
- (void)onTokenRefreshFailedWithMessage:(nonnull NSString *)message;


@end
/// @endcond

