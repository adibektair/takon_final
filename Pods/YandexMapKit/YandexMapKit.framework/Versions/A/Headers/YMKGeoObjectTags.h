#import <Foundation/Foundation.h>

/**
 * Geo object tags.
 */
@interface YMKGeoObjectTags : NSObject

@property (nonatomic, readonly, nonnull) NSArray<NSString *> *tags;


+ (nonnull YMKGeoObjectTags *)geoObjectTagsWithTags:(nonnull NSArray<NSString *> *)tags;


@end

