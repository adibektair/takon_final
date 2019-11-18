#import <YandexMapKit/YMKCameraPosition.h>
#import <YandexMapKit/YMKLocationViewSource.h>
#import <YandexMapKit/YMKUserLocationObjectListener.h>
#import <YandexMapKit/YMKUserLocationTapListener.h>

#import <UIKit/UIKit.h>

/**
 * Use the UserLocationLayer interface to manage the location icon: its
 * appearance, following mode, data source and so on.
 */
@interface YMKUserLocationLayer : NSObject

/**
 * Sets user location visibility.
 */
- (void)setVisibleWithOn:(BOOL)on;


/**
 * Checks if user location is visible.
 */
- (BOOL)isVisible;


/**
 * Enables/disables heading mode. If heading mode is enabled, the map is
 * rotated. If heading mode is disabled, the location icon is rotated.
 */
@property (nonatomic, getter=isHeadingEnabled) BOOL headingEnabled;

/**
 * Sets the anchor to the specified position in pixels and enables
 * Anchor mode. (0, 0) denotes the top-left corner of the screen.
 *
 * @param anchorNormal The anchor position when the app is not on a
 * steady course; usually, the center of the screen.
 * @param anchorCourse An anchor position near the bottom line for
 * steady course mode.
 */
- (void)setAnchorWithAnchorNormal:(CGPoint)anchorNormal
                     anchorCourse:(CGPoint)anchorCourse;


/**
 * Resets anchor mode.
 */
- (void)resetAnchor;


/**
 * Returns true if anchor mode is set, and false otherwise.
 */
@property (nonatomic, readonly, getter=isAnchorEnabled) BOOL anchorEnabled;

/**
 * Enables/disables auto zoom.
 */
@property (nonatomic, getter=isAutoZoomEnabled) BOOL autoZoomEnabled;

/**
 * Calculates the camera position that projects the current location
 * into view. If the current location is unknown, returns none. If the
 * current location is known, returns the camera position that displays
 * the location position.
 */
- (nullable YMKCameraPosition *)cameraPosition;


/**
 * Sets/gets the data source.
 *
 * Remark:
 * @param source has optional type, it may be uninitialized.
 */
- (void)setSourceWithSource:(nullable YMKLocationViewSource *)source;


/**
 * Sets/resets the tap listener.
 *
 * Remark:
 * @param tapListener has optional type, it may be uninitialized.
 */
- (void)setTapListenerWithTapListener:(nullable id<YMKUserLocationTapListener>)tapListener;


/**
 * Sets/resets the object listener.
 *
 * Remark:
 * @param objectListener has optional type, it may be uninitialized.
 */
- (void)setObjectListenerWithObjectListener:(nullable id<YMKUserLocationObjectListener>)objectListener;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

