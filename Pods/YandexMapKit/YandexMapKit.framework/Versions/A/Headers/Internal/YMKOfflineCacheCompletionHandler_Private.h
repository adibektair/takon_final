#import <YandexMapKit/Internal/YMKOfflineCacheManager_Private.h>

@interface YMKOfflineCacheManager(CompletionHandler)

- (void)setCompletionHandler:(void (^)(void))completionHandler forBackgroundURLSession:(NSString *)identifier;

@end
