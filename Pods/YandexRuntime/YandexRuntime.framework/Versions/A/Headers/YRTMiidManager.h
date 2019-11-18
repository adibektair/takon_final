#import <Foundation/Foundation.h>

typedef void(^YRTMiidDelegate)(
    NSString * _Nullable miid,
    NSError * _Nullable error);


/// @cond EXCLUDE
@interface YRTMiidManager : NSObject

/**
 * Submits request. Can be called multiple times.
 */
- (void)submitWithMiidDelegate:(nonnull YRTMiidDelegate)miidDelegate;


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

