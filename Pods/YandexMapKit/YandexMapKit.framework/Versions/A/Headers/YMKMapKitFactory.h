#import <YandexMapKit/YMKMapKit.h>

@interface YMKMapKit (Factory)

+ (instancetype)mapKit;
+ (instancetype)sharedInstance;
+ (void)setApiKey:(NSString*)apiKey;
- (void)setCompletionHandler:(void (^)(void))completionHandler
     forBackgroundURLSession:(NSString *)identifier;

@end
