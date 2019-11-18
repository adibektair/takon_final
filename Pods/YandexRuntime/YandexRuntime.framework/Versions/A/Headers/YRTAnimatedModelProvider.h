#import <Foundation/Foundation.h>
#import <YandexRuntime/YRTAnimatedModel.h>

@protocol YRTAnimatedModelProvider

- (NSString*)modelId;
- (YRTAnimatedModel*)model;

@end
