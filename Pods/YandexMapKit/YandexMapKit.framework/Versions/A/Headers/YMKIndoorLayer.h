#import <YandexMapKit/YMKIndoorStateListener.h>

/// @cond EXCLUDE
@interface YMKIndoorLayer : NSObject

/**
 * Indicates whether the layer is displayed on a map.
 */
@property (nonatomic, getter=isVisible) BOOL visible;

/**
 * Subscribe to layer indoor state change events.
 */
- (void)addListenerWithIndoorStateListener:(nonnull id<YMKIndoorStateListener>)indoorStateListener;


/**
 * Unsubscribe from layer indoor state change events.
 */
- (void)removeListenerWithIndoorStateListener:(nonnull id<YMKIndoorStateListener>)indoorStateListener;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
/// @endcond

