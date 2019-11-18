#import <UIKit/UIKit.h>

@protocol YRTArchiving <NSObject>

- (BOOL)isReader;

#pragma mark - Primitives

- (BOOL)addBool:(BOOL)value;
- (double)addDouble:(double)value;
- (float)addFloat:(float)value;
- (NSInteger)addInteger:(NSInteger)value;
- (NSUInteger)addUnsignedInteger:(NSUInteger)value;
- (long long)addLongLong:(long long)value;

#pragma mark - NSNumber

- (NSNumber *)addBool:(NSNumber *)number
             optional:(BOOL)optional;

- (NSNumber *)addDouble:(NSNumber *)number
               optional:(BOOL)optional;

- (NSNumber *)addFloat:(NSNumber *)number
              optional:(BOOL)optional;

- (NSNumber *)addInteger:(NSNumber *)number
                optional:(BOOL)optional;

- (NSNumber *)addUnsignedInteger:(NSNumber *)number
                        optional:(BOOL)optional;

- (NSNumber *)addLongLong:(NSNumber *)number
                 optional:(BOOL)optional;

#pragma mark - NSString

- (NSString *)addString:(NSString *)string
               optional:(BOOL)optional;

#pragma mark - NSData

- (NSData *)addData:(NSData *)data
           optional:(BOOL)optional;

#pragma mark - UIColor

- (UIColor *)addColor:(UIColor *)color
             optional:(BOOL)optional;

#pragma mark - YRTArchivingHandler

typedef id (^YRTArchivingHandler)(id object, id<YRTArchiving> archive);

#pragma mark - NSArray

- (NSArray *)addArray:(NSArray *)array
             optional:(BOOL)optional
              handler:(YRTArchivingHandler)handler;

#pragma mark - NSDictionary

- (NSDictionary *)addDictionary:(NSDictionary *)dictionary
                       optional:(BOOL)optional
                     keyHandler:(YRTArchivingHandler)keyHandler
                   valueHandler:(YRTArchivingHandler)valueHandler;

#pragma mark - NSDate

- (NSDate *)addDate:(NSDate *)date
           optional:(BOOL)optional;

#pragma mark - NSTimeInterval

- (NSTimeInterval)addTimeInterval:(NSTimeInterval)timeInterval;

- (NSNumber *)addTimeInterval:(NSNumber *)timeInterval
                     optional:(BOOL)optional;

#pragma mark - YRTClasses

- (id)addObject:(id)object
       optional:(BOOL)optional
          class:(Class)cls;

- (id)addObject:(id)object
        handler:(YRTArchivingHandler)handler;

#pragma mark - Custom object types

- (CGPoint)addCGPoint:(CGPoint)point;

- (NSValue *)addCGPoint:(NSValue *)point
               optional:(BOOL)optional;

@end
