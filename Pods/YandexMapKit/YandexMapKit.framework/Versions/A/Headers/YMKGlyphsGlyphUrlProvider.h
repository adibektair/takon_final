#import <YandexMapKit/YMKGlyphsGlyphIdRange.h>

/// @cond EXCLUDE
@protocol YMKGlyphsGlyphUrlProvider <NSObject>

- (nonnull NSString *)formatUrlWithFontId:(nonnull NSString *)fontId
                                    range:(nonnull YMKGlyphsGlyphIdRange *)range;


@end
/// @endcond
