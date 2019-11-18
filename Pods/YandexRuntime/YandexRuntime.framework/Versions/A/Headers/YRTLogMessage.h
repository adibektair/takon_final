#import <Foundation/Foundation.h>

/// @cond EXCLUDE
typedef NS_ENUM(NSUInteger, YRTLogMessageLogLevel) {

    YRTLogMessageLogLevelError,

    YRTLogMessageLogLevelWarning,

    YRTLogMessageLogLevelInfo,

    YRTLogMessageLogLevelDebug
};


@interface YRTLogMessage : NSObject

@property (nonatomic, readonly, nonnull) NSDate *time;

@property (nonatomic, readonly) YRTLogMessageLogLevel level;

@property (nonatomic, readonly, nonnull) NSString *scope;

@property (nonatomic, readonly, nonnull) NSString *message;

@property (nonatomic, readonly, nonnull) NSString *verboseInfo;


+ (nonnull YRTLogMessage *)logMessageWithTime:(nonnull NSDate *)time
                                        level:( YRTLogMessageLogLevel)level
                                        scope:(nonnull NSString *)scope
                                      message:(nonnull NSString *)message
                                  verboseInfo:(nonnull NSString *)verboseInfo;


@end
/// @endcond

