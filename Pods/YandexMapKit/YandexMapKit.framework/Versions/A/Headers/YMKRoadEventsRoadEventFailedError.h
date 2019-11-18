#import <YandexRuntime/YRTError.h>

/// @cond EXCLUDE
typedef NS_ENUM(NSUInteger, YMKRoadEventsRoadEventFailedErrorCode) {

    /**
     * The server returned an error that is not known in the API version you
     * are using.
     */
    YMKRoadEventsRoadEventFailedErrorCodeUnknown,

    /**
     * The user has been banned.
     */
    YMKRoadEventsRoadEventFailedErrorCodeBanned,

    /**
     * The user is too far from the event.
     */
    YMKRoadEventsRoadEventFailedErrorCodeTooFar,

    /**
     * The user is performing certain actions too often. Wait a bit and try
     * again.
     */
    YMKRoadEventsRoadEventFailedErrorCodeTooOften
};


@interface YMKRoadEventsRoadEventFailedError : YRTError

@property (nonatomic, readonly) YMKRoadEventsRoadEventFailedErrorCode code;

/**
 * Localized error description suitable for end user.
 */
@property (nonatomic, readonly, nonnull) NSString *description;

@end
/// @endcond

