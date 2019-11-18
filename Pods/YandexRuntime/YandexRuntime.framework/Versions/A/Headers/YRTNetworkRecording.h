#import <Foundation/Foundation.h>

@class YRTNetworkPlayer;
@class YRTNetworkRecorder;

typedef void(^YRTFileOperationsListener)(
    NSError * _Nullable error);


@interface YRTNetworkRecording : NSObject

/// @cond EXCLUDE
+ (nullable YRTNetworkRecorder *)createRecorder;
/// @endcond


/// @cond EXCLUDE
+ (nullable YRTNetworkPlayer *)createPlayer;
/// @endcond


@end
