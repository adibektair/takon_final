#import <YandexMapKit/YMKTileId.h>
#import <YandexMapKit/YMKVersion.h>

/**
 * Provides a formatted URL.
 */
@protocol YMKTilesUrlProvider <NSObject>

/**
 * Creates a URL based on the tile ID and version.
 */
- (nonnull NSString *)formatUrlWithTileId:(nonnull YMKTileId *)tileId
                                  version:(nonnull YMKVersion *)version;


@end
