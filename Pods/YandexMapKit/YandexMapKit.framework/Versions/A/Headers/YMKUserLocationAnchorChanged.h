#import <YandexMapKit/YMKObjectEvent.h>
#import <YandexMapKit/YMKUserLocation.h>

/**
 * Event for a change in the user location icon anchor.
 */
@interface YMKUserLocationAnchorChanged : YMKObjectEvent

/**
 * Gets the type of anchor used.
 */
@property (nonatomic, readonly) YMKUserLocationAnchorType anchorType;

@end

