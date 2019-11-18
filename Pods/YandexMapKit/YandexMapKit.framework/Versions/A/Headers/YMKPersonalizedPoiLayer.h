#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YMKPersonalizedPoiLayer : NSObject

/**
 * Indicates whether the layer is displayed on a map or not.
 */
- (BOOL)isVisible;


/**
 * Display or hide the layer on a map.
 */
- (void)setVisibleWithOn:(BOOL)on;


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

