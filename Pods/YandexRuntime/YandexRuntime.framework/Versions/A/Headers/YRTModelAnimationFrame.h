#import <Foundation/Foundation.h>
#import <YandexRuntime/YRTModelProvider.h>

@interface YRTModelAnimationFrame : NSObject

- (id)initWithModel:(id<YRTModelProvider>)model duration:(NSTimeInterval)duration;
- (id<YRTModelProvider>)model;
- (NSTimeInterval)duration;

@end
