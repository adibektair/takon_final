#import <Foundation/Foundation.h>

/**
 * The time it took to load map elements.
 */
@interface YMKMapLoadStatistics : NSObject

@property (nonatomic, readonly) NSTimeInterval curZoomGeometryLoaded;

@property (nonatomic, readonly) NSTimeInterval curZoomPlacemarksLoaded;

@property (nonatomic, readonly) NSTimeInterval curZoomLabelsLoaded;

@property (nonatomic, readonly) NSTimeInterval geometryLoaded;

/**
 * The time it took to load delayed geometry.
 */
@property (nonatomic, readonly) NSTimeInterval delayedGeometryLoaded;

/**
 * The time it took to load labels.
 */
@property (nonatomic, readonly) NSTimeInterval labelsLoaded;

/**
 * The time it took to load placemarks.
 */
@property (nonatomic, readonly) NSTimeInterval placemarksLoaded;

/**
 * The time it took to load models.
 */
@property (nonatomic, readonly) NSTimeInterval modelsLoaded;

/**
 * The time it took to load all map objects.
 */
@property (nonatomic, readonly) NSTimeInterval fullyLoaded;

/**
 * The time it took for all map objects to appear.
 */
@property (nonatomic, readonly) NSTimeInterval fullyAppeared;

@property (nonatomic, readonly) NSInteger renderObjectCount;

/**
 * Tile memory usage in bytes
 */
@property (nonatomic, readonly) NSUInteger tileMemoryUsage;


+ (nonnull YMKMapLoadStatistics *)mapLoadStatisticsWithCurZoomGeometryLoaded:( NSTimeInterval)curZoomGeometryLoaded
                                                     curZoomPlacemarksLoaded:( NSTimeInterval)curZoomPlacemarksLoaded
                                                         curZoomLabelsLoaded:( NSTimeInterval)curZoomLabelsLoaded
                                                              geometryLoaded:( NSTimeInterval)geometryLoaded
                                                       delayedGeometryLoaded:( NSTimeInterval)delayedGeometryLoaded
                                                                labelsLoaded:( NSTimeInterval)labelsLoaded
                                                            placemarksLoaded:( NSTimeInterval)placemarksLoaded
                                                                modelsLoaded:( NSTimeInterval)modelsLoaded
                                                                 fullyLoaded:( NSTimeInterval)fullyLoaded
                                                               fullyAppeared:( NSTimeInterval)fullyAppeared
                                                           renderObjectCount:( NSInteger)renderObjectCount
                                                             tileMemoryUsage:( NSUInteger)tileMemoryUsage;


@end

