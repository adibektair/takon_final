#import <YandexMapKit/YMKGlyphsDefaultUrlProvider.h>

#include <yandex/maps/mapkit/glyphs/default_glyph_url_provider.h>

#include <memory>

@interface YMKGlyphsDefaultUrlProvider ()

- (id)initWithNative:(const std::shared_ptr<yandex::maps::mapkit::glyphs::DefaultGlyphUrlProvider>&)native;

@end
