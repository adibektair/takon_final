#import <YandexMapKit/YMKObjectEvent.h>

@class YMKUserLocationView;

/**
 * User location events object listener. Use it to customize the user
 * location view. Although some callbacks are unused, the generic
 * structure of the interface is suitable for object layer listeners.
 */
@protocol YMKUserLocationObjectListener <NSObject>

/**
 * Called when the layer object is added. It is called once when the
 * user location icon appears the first time.
 */
- (void)onObjectAddedWithView:(nonnull YMKUserLocationView *)view;


/**
 * Called when the layer object is being removed. It is never called for
 * the user location icon.
 */
- (void)onObjectRemovedWithView:(nonnull YMKUserLocationView *)view;


/**
 * Called when the layer object is being updated. The 'event' parameter
 * can be one of the derived types.
 */
- (void)onObjectUpdatedWithView:(nonnull YMKUserLocationView *)view
                          event:(nonnull YMKObjectEvent *)event;


@end
