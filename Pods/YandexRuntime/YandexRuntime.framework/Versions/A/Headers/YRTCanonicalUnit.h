#import <Foundation/Foundation.h>

/**
 * Represents a unit with the value and measurement separated.
 */
@interface YRTCanonicalUnit : NSObject

/**
 * The unit of measurement.
 */
@property (nonatomic, readonly, nonnull) NSString *unit;

/**
 * The numerical value.
 */
@property (nonatomic, readonly) double value;


+ (nonnull YRTCanonicalUnit *)canonicalUnitWithUnit:(nonnull NSString *)unit
                                              value:( double)value;


@end

