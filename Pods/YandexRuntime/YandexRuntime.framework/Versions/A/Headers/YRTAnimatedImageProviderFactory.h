#import <Foundation/Foundation.h>
#import <YandexRuntime/YRTAnimatedImage.h>

@interface YRTAnimatedImageProviderFactory : NSObject

+ (id)fromFile:(NSString*)path;
+ (id)fromData:(NSData*)data;
+ (id)fromAnimatedImage:(YRTAnimatedImage*)animatedImage;

@end
