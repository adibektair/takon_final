#import <YandexMapKit/YMKArrivalPoint.h>

/**
 * List of arrival points for the GeoObject.
 */
@interface YMKArrivalObjectMetadata : NSObject

/**
 * List of ArrivalPoint objects.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKArrivalPoint *> *arrivalPoints;


+ (nonnull YMKArrivalObjectMetadata *)arrivalObjectMetadataWithArrivalPoints:(nonnull NSArray<YMKArrivalPoint *> *)arrivalPoints;


@end

