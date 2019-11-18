#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YRTReportData : NSObject

@property (nonatomic, readonly, nonnull) NSDate *startTime;

@property (nonatomic, readonly, nonnull) NSDate *endTime;

/**
 * Optional property, can be nil.
 */
@property (nonatomic, nullable) NSString *issueId;

- (nonnull NSArray<NSDate *> *)problemMarks;


- (nonnull NSData *)data;


@end
/// @endcond

