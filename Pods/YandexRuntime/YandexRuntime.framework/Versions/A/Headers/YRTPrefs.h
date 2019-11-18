#import <Foundation/Foundation.h>

/**
 * The .h generated from this idl should define the same entities as
 * libs/i18n/include/yandex/maps/i18n/prefs.h from the mapscore repo.
 * Please edit these two files simultaneously. The system of measurement
 * to use.
 */
typedef NS_ENUM(NSUInteger, YRTSystemOfMeasurement) {

    YRTSystemOfMeasurementDefault,

    /**
     * Metric system. (kilometers etc)
     */
    YRTSystemOfMeasurementMetric,

    /**
     * Imperial system. (miles etc)
     */
    YRTSystemOfMeasurementImperial
};


/**
 * Time format to use.
 */
typedef NS_ENUM(NSUInteger, YRTTimeFormat) {

    YRTTimeFormatDefault,

    /**
     * 24-hour time format.
     */
    YRTTimeFormatH24,

    /**
     * 12-hour time format with AM/PM marker.
     */
    YRTTimeFormatH12
};

