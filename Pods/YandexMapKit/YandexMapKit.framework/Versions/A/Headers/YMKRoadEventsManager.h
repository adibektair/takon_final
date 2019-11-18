#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKRoadEventsEntrySession.h>
#import <YandexMapKit/YMKRoadEventsEventInfoSession.h>
#import <YandexMapKit/YMKRoadEventsRoadEventSession.h>
#import <YandexMapKit/YMKRoadEventsRoadEvents.h>
#import <YandexMapKit/YMKRoadEventsVoteSession.h>

@class YMKRoadEventsFeedSession;

/// @cond EXCLUDE
@interface YMKRoadEventsManager : NSObject

/**
 * Begins async request to create a road event.
 *
 * @param eventType Type of event to create.
 * @param descriptionText Event description.
 * @param eventLocation new Event location.
 * @param roadEventListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsRoadEventSession *)addEventWithEventType:(YMKRoadEventsEventType)eventType
                                                 descriptionText:(nonnull NSString *)descriptionText
                                                   eventLocation:(nonnull YMKPoint *)eventLocation
                                                 responseHandler:(nonnull YMKRoadEventsRoadEventSessionResponseHandler)responseHandler;


/**
 * Begins asynchronous request for road event info.
 *
 * @param eventId ID of the event to request information for.
 * @param eventInfoListener Listener for result or error.
 */
- (nonnull YMKRoadEventsEventInfoSession *)requestEventInfoWithEventId:(nonnull NSString *)eventId
                                                       responseHandler:(nonnull YMKRoadEventsEventInfoSessionResponseHandler)responseHandler;


/**
 * Begins async request to vote up a road event.
 *
 * @param eventId ID of the event to vote for.
 * @param voteListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsVoteSession *)voteUpWithEventId:(nonnull NSString *)eventId
                                        responseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;


/**
 * Begins async request to vote down a road event.
 *
 * @param eventId ID of the event to vote for.
 * @param voteListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsVoteSession *)voteDownWithEventId:(nonnull NSString *)eventId
                                          responseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;


/**
 * Begins async request to get comments.
 *
 * @param eventId ID of the event to get comments for.
 *
 * @return Comments session.
 */
- (nonnull YMKRoadEventsFeedSession *)commentsWithEventId:(nonnull NSString *)eventId;


/**
 * Begins async request to add a comment.
 *
 * @param eventId ID of the event to add a comment for.
 * @param text Comment text.
 * @param entryListener Receives the new comment entry or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsEntrySession *)addCommentWithEventId:(nonnull NSString *)eventId
                                                        text:(nonnull NSString *)text
                                             responseHandler:(nonnull YMKRoadEventsEntrySessionResponseHandler)responseHandler;


@end
/// @endcond

