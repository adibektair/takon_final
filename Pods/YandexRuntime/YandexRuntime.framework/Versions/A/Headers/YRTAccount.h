#import <Foundation/Foundation.h>

@class YRTTokenDelegate;

/// @cond EXCLUDE
@protocol YRTAccount <NSObject>

/**
 * Get the user's UID
 */
- (nonnull NSString *)uid;


/**
 * Makes a token request for the provider. See @{TokenListener} for
 * additional information.
 */
- (void)requestTokenWithTokenListener:(nonnull YRTTokenDelegate *)tokenListener;


/**
 * Invalidates the OAuth token for an active account. The next token
 * request occurs on a new OAuth token request from XToken.
 */
- (void)invalidateToken:(nonnull NSString *)token;


/**
 * Creates the HTTP authorization header for requests. return null if
 * default authorization needed ('OAuth token').
 */
- (nullable NSString *)httpAuthWithToken:(nonnull NSString *)token;


@end
/// @endcond
