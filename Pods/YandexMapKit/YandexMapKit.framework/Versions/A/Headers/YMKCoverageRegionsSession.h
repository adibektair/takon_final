#import <YandexMapKit/YMKCoverageRegion.h>

/// @cond EXCLUDE
typedef void(^YMKCoverageRegionsSessionResponseHandler)(
    NSArray<YMKCoverageRegion *> * _Nullable regions,
    NSError * _Nullable error);


/**
 * Allows to repeat or cancel the request for a list of regions.
 */
@interface YMKCoverageRegionsSession : NSObject

/**
 * Repeats the specified request with the same parameters.
 */
- (void)retryWithResponseHandler:(nonnull YMKCoverageRegionsSessionResponseHandler)responseHandler;


/**
 * Cancels the request.
 */
- (void)cancel;


@end
/// @endcond

