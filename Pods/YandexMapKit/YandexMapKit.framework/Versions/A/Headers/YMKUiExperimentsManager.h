#import <YandexMapKit/YMKUiExperimentsListener.h>

/// @cond EXCLUDE
@interface YMKUiExperimentsManager : NSObject

/**
 * Currently cached parameters.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> *parameters;

/**
 * If you want to check only one key, dealing with the whole dictionary
 * is cumbersome. This method returns the currently cached value of a
 * parameter with the given key, if that parameter was previously
 * received.
 */
- (nullable NSString *)getValueWithKey:(nonnull NSString *)key;


/**
 * This function is for testing purposes only.
 *
 * Remark:
 * @param value has optional type, it may be uninitialized.
 */
- (void)setValueWithServiceId:(nonnull NSString *)serviceId
                parameterName:(nonnull NSString *)parameterName
                        value:(nullable NSString *)value;


- (void)subscribeWithExperimentsListener:(nonnull id<YMKUiExperimentsListener>)experimentsListener;


- (void)unsubscribeWithExperimentsListener:(nonnull id<YMKUiExperimentsListener>)experimentsListener;


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

