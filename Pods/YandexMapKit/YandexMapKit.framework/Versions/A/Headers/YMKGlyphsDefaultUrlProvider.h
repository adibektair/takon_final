#import <YandexMapKit/YMKGlyphsGlyphUrlProvider.h>

/// @cond EXCLUDE
@interface YMKGlyphsDefaultUrlProvider : NSObject<YMKGlyphsGlyphUrlProvider>

- (NSString *)formatUrlWithFontId:(NSString *)fontId
                            range:(YMKGlyphsGlyphIdRange *)range;

- (void)setUrlPattern:(NSString *)urlPattern;

@end
/// @endcond