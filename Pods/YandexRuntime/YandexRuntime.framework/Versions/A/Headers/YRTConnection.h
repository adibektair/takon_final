#import <YandexRuntime/YRTClient.h>
#import <YandexRuntime/YRTConnectionStateListener.h>
#import <YandexRuntime/YRTSendDataResult.h>

/// @cond EXCLUDE
@protocol YRTConnection <NSObject>

- (BOOL)connectWithClient:(nonnull YRTClient *)client
                        l:(nonnull YRTConnectionStateListener *)l;


- (void)disconnect;


- (YRTSendDataResult)sendDataWithData:(nonnull NSData *)data;


@end
/// @endcond
