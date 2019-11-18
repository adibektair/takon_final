#import <YandexMapKit/YMKUri.h>

/**
 * URI metadata.
 */
@interface YMKUriObjectMetadata : NSObject

/**
 * Gets a list of URIs.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKUri *> *uris;


+ (nonnull YMKUriObjectMetadata *)uriObjectMetadataWithUris:(nonnull NSArray<YMKUri *> *)uris;


@end

