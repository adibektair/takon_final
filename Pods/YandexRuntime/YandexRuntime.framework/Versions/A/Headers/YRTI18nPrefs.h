#import <YandexRuntime/YRTPrefs.h>

/**
 * Localization preferences.
 */
@interface YRTI18nPrefs : NSObject

/**
 * System of measurement (metric or imperial).
 */
@property (nonatomic, readonly) YRTSystemOfMeasurement som;

/**
 * Time format (12- or 24-hour).
 */
@property (nonatomic, readonly) YRTTimeFormat timeFormat;


+ (nonnull YRTI18nPrefs *)i18nPrefsWithSom:( YRTSystemOfMeasurement)som
                                timeFormat:( YRTTimeFormat)timeFormat;


@end

