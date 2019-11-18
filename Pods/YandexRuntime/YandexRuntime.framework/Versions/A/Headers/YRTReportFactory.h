#import <Foundation/Foundation.h>

@class YRTReportData;

/// @cond EXCLUDE
@interface YRTReportFactory : NSObject

- (nonnull YRTReportData *)createReportDataWithData:(nonnull NSData *)data;


@end
/// @endcond

