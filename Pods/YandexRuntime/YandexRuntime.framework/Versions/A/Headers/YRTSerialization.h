#pragma once

#import <YandexRuntime/YRTArchiving.h>

@protocol YRTSerialization <NSObject>

- (void)serialize:(id<YRTArchiving>)archive;

@end
