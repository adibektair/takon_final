#import <YandexRuntime/YRTI18nManager.h>

@interface YRTI18nManagerFactory : NSObject

/**
 * Returns the locale currently used by the runtime.
 */
+ (void)getLocaleWithLocaleDelegate:(nonnull YRTLocaleDelegate)localeDelegate;


/**
 * Sets the runtime locale. The user needs to restart the application
 * for the changes to take effect.
 */
+ (void)setLocaleWithLanguage:(nonnull NSString *)language
                      country:(nonnull NSString *)country
         localeUpdateDelegate:(nonnull YRTLocaleUpdateDelegate)localeUpdateDelegate;


/**
 * Sets a custom library language. Country settings are determined by
 * system preferences. The user needs to restart the application for the
 * changes to take effect.
 */
+ (void)setLocaleWithLanguage:(nonnull NSString *)language
         localeUpdateDelegate:(nonnull YRTLocaleUpdateDelegate)localeUpdateDelegate;


/**
 * Resets locale settings to system defaults.
 */
+ (void)resetLocaleWithLocaleResetDelegate:(nonnull YRTLocaleResetDelegate)localeResetDelegate;


/**
 * Gets the internationalization manager interface.
 */
+ (nonnull YRTI18nManager *)getI18nManagerInstance;


@end
