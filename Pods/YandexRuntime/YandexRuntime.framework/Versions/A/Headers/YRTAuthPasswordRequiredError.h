#import <YandexRuntime/YRTError.h>

/// @cond EXCLUDE
/**
 * The XToken is not valid anymore. The password must be re-entered.
 */
@interface YRTAuthPasswordRequiredError : YRTError

@property (nonatomic, readonly, nonnull) id data;

@end
/// @endcond

