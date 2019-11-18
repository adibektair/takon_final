#import <YandexMapKit/YMKObjectEvent.h>
#import <YandexMapKit/YMKUserLocation.h>

/**
 * This event triggers when the user location icon type is changed.
 */
@interface YMKUserLocationIconChanged : YMKObjectEvent

/**
 * Gets the type of user location icon used.
 */
@property (nonatomic, readonly) YMKUserLocationIconType iconType;

@end

