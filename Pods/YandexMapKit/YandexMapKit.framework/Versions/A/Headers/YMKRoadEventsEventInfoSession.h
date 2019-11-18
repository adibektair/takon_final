#import <YandexMapKit/YMKGeoObject.h>

#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTRemoteError.h>

/// @cond EXCLUDE
typedef void(^YMKRoadEventsEventInfoSessionResponseHandler)(
    YMKGeoObject * _Nullable event,
    NSError * _Nullable error);


/**
 * Session for requesting road event info.
 */
@interface YMKRoadEventsEventInfoSession : NSObject

/**
 * One of the following errors can happen: YRTNotFoundError,
 * {@runtime.network.NetworkError}, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEventInfoSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

