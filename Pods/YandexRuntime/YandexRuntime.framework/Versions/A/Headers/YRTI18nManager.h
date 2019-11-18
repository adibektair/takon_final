#import <YandexRuntime/YRTCanonicalUnit.h>
#import <YandexRuntime/YRTI18nPrefs.h>
#import <YandexRuntime/YRTPrefs.h>

typedef void(^YRTLocaleUpdateDelegate)(
    NSError * _Nullable error);


typedef void(^YRTLocaleResetDelegate)(
    NSError * _Nullable error);


typedef void(^YRTLocaleDelegate)(
    NSString * _Nullable locale,
    NSError * _Nullable error);


/**
 * Localization manager.
 */
@interface YRTI18nManager : NSObject

/**
 * Converts a distance value to the current locale.
 */
- (nonnull NSString *)localizeDistanceWithDistance:(NSInteger)distance;


/**
 * Converts a duration to the current locale.
 */
- (nonnull NSString *)localizeDurationWithDuration:(NSInteger)duration;


/**
 * Converts speed to the current locale.
 */
- (nonnull NSString *)localizeSpeedWithSpeed:(double)speed;


/**
 * Converts data size to the current locale.
 */
- (nonnull NSString *)localizeDataSizeWithDataSize:(long long)dataSize;


/**
 * Represents the speed with the value and unit of measurement
 * separated.
 */
- (nonnull YRTCanonicalUnit *)canonicalSpeedWithSpeed:(double)speed;


/**
 * Localizes a value represented by canonical units.
 */
- (nonnull NSString *)localizeCanonicalUnitWithCanonicalUnit:(nonnull YRTCanonicalUnit *)canonicalUnit;


/**
 * Localization preferences.
 */
@property (nonatomic, nonnull) YRTI18nPrefs *prefs;

/**
 * System of measurement used.
 */
@property (nonatomic) YRTSystemOfMeasurement som;

/**
 * Preferred time format.
 */
@property (nonatomic) YRTTimeFormat timeFormat;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

