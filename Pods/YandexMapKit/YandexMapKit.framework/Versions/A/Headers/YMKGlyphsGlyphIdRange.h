#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YMKGlyphsGlyphIdRange : NSObject

@property (nonatomic, readonly) NSUInteger firstGlyphId;

@property (nonatomic, readonly) NSUInteger lastGlyphId;


+ (nonnull YMKGlyphsGlyphIdRange *)glyphIdRangeWithFirstGlyphId:( NSUInteger)firstGlyphId
                                                    lastGlyphId:( NSUInteger)lastGlyphId;


@end
/// @endcond

