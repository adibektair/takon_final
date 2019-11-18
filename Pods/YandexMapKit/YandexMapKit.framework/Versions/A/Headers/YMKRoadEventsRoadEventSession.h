#import <YandexMapKit/YMKGeoObject.h>

#import <YandexRuntime/YRTAuthPasswordRequiredError.h>
#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTRemoteError.h>

@class YMKRoadEventsRoadEventFailedError;

/// @cond EXCLUDE
typedef void(^YMKRoadEventsRoadEventSessionResponseHandler)(
    YMKGeoObject * _Nullable event,
    NSError * _Nullable error);


/**
 * Road event creation session.
 */
@interface YMKRoadEventsRoadEventSession : NSObject

/**
 * One of the following errors can happen:
 * YMKRoadEventsRoadEventFailedError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsRoadEventSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

