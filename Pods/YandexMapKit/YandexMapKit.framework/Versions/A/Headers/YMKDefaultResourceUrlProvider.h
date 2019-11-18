#import <YandexMapKit/YMKResourceUrlProvider.h>

// @cond EXCLUDE
@interface YMKDefaultResourceUrlProvider : NSObject<YMKResourceUrlProvider>

- (NSString *)formatUrlWithResourceId:(NSString *)resId;

- (void)setUrlBase:(NSString *)urlBase;

@end
// @endcond