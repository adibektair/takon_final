#import <YandexMapKit/YMKTilesUrlProvider.h>
#import <YandexMapKit/YMKZoomRange.h>

// @cond EXCLUDE
@interface YMKTilesDefaultUrlProvider : NSObject<YMKTilesUrlProvider>

- (NSString *)formatUrlWithTileId:(YMKTileId *)tileId
                          version:(YMKVersion *)version;

- (void)setUrlPattern:(NSString *)urlPattern;

- (void)setZoomRanges:(NSArray *)zoomRanges;

@end
// @endcond