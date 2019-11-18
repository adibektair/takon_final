#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YMKTaxiMoney : NSObject

@property (nonatomic, readonly) double value;

@property (nonatomic, readonly, nonnull) NSString *text;

@property (nonatomic, readonly, nonnull) NSString *currency;


+ (nonnull YMKTaxiMoney *)moneyWithValue:( double)value
                                    text:(nonnull NSString *)text
                                currency:(nonnull NSString *)currency;


@end
/// @endcond

