#import <YandexMapKit/YMKRoadEventsEntry.h>

#import <YandexRuntime/YRTAuthPasswordRequiredError.h>
#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTRemoteError.h>

@class YMKRoadEventsRoadEventFailedError;

/// @cond EXCLUDE
typedef void(^YMKRoadEventsEntrySessionResponseHandler)(
    YMKRoadEventsEntry * _Nullable entry,
    NSError * _Nullable error);


/**
 * Session for adding comments.
 */
@interface YMKRoadEventsEntrySession : NSObject

/**
 * One of the following errors can occur:
 * YMKRoadEventsRoadEventFailedError, YRTNotFoundError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEntrySessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

