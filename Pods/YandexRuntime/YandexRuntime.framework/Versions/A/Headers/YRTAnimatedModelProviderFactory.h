#import <Foundation/Foundation.h>
#import <YandexRuntime/YRTAnimatedModel.h>
#import <YandexRuntime/YRTAnimatedModelProvider.h>

@interface YRTAnimatedModelProviderFactory : NSObject

+ (id<YRTAnimatedModelProvider>)fromAnimatedModel:(YRTAnimatedModel*)animatedModel;

@end
