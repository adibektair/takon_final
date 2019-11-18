#import <YandexMapKit/YMKCircle.h>
#import <YandexMapKit/YMKClusterListener.h>
#import <YandexMapKit/YMKIconStyle.h>
#import <YandexMapKit/YMKMapObject.h>
#import <YandexMapKit/YMKMapObjectCollectionListener.h>
#import <YandexMapKit/YMKMapObjectVisitor.h>
#import <YandexMapKit/YMKModelStyle.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKPolygon.h>
#import <YandexMapKit/YMKPolyline.h>

#import <YandexRuntime/YRTAnimatedImageProvider.h>
#import <YandexRuntime/YRTAnimatedModelProvider.h>
#import <YandexRuntime/YRTViewProvider.h>

#import <UIKit/UIKit.h>

@class YMKCircleMapObject;
@class YMKClusterizedPlacemarkCollection;
@class YMKColoredPolylineMapObject;
@class YMKPlacemarkMapObject;
@class YMKPlacemarksStyler;
@class YMKPolygonMapObject;
@class YMKPolylineMapObject;

/**
 * A collection of map objects that can hold any set of MapObject items,
 * including nested collections.
 */
@interface YMKMapObjectCollection : YMKMapObject

/**
 * Creates a new empty placemark and adds it to the current collection.
 * Hint: to add a large amount of empty placemarks use
 * addEmptyPlacemarks method.
 */
- (nonnull YMKPlacemarkMapObject *)addEmptyPlacemarkWithPoint:(nonnull YMKPoint *)point;


/**
 * Creates new empty placemarks and adds them to the current collection.
 *
 * Relevant for Android: this method provides better performance for
 * adding a large number of empty placemarks than multiple calls of
 * addEmptyPlacemark.
 */
- (nonnull NSArray<YMKPlacemarkMapObject *> *)addEmptyPlacemarksWithPoints:(nonnull NSArray<YMKPoint *> *)points;


/**
 * Creates a new placemark with the default icon and style, and adds it
 * to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point;


/**
 * Creates a new placemark with the default style and adds it to the
 * current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                   image:(nonnull UIImage *)image;


/**
 * Creates a new placemark and adds it to the current collection. Hint:
 * to add a large amount of placemarks use addPlacemarks method.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                   image:(nonnull UIImage *)image
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new view placemark with default style and adds it to the
 * current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                    view:(nonnull YRTViewProvider *)view;


/**
 * Creates a new view placemark and adds it to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                    view:(nonnull YRTViewProvider *)view
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new placemark with animated icon and adds it to the current
 * collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                           animatedImage:(nonnull id<YRTAnimatedImageProvider>)animatedImage
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new placemark with animated model and adds it to the
 * current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                           animatedModel:(nonnull id<YRTAnimatedModelProvider>)animatedModel
                                                   style:(nonnull YMKModelStyle *)style;


/**
 * Creates new placemarks and adds them to the current collection.
 * Relevant for Android: this method provides better performance for
 * adding a large number of placemarks than multiple calls of
 * addPlacemark.
 */
- (nonnull NSArray<YMKPlacemarkMapObject *> *)addPlacemarksWithPoints:(nonnull NSArray<YMKPoint *> *)points
                                                                image:(nonnull UIImage *)image
                                                                style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new polyline and adds it to the current collection.
 */
- (nonnull YMKPolylineMapObject *)addPolylineWithPolyline:(nonnull YMKPolyline *)polyline;


/**
 * Creates a new colored polyline and adds it to the current collection.
 */
- (nonnull YMKColoredPolylineMapObject *)addColoredPolylineWithPolyline:(nonnull YMKPolyline *)polyline;


/**
 * Creates a new colored polyline with an empty geometry and adds it to
 * the current collection.
 */
- (nonnull YMKColoredPolylineMapObject *)addColoredPolyline;


/**
 * Creates a new polygon and adds it to the current collection.
 */
- (nonnull YMKPolygonMapObject *)addPolygonWithPolygon:(nonnull YMKPolygon *)polygon;


/**
 * Creates a new circle with the specified style and adds it to the
 * current collection.
 */
- (nonnull YMKCircleMapObject *)addCircleWithCircle:(nonnull YMKCircle *)circle
                                        strokeColor:(nonnull UIColor *)strokeColor
                                        strokeWidth:(float)strokeWidth
                                          fillColor:(nonnull UIColor *)fillColor;


/**
 * Creates a new nested collection of map objects.
 */
- (nonnull YMKMapObjectCollection *)addCollection;


/**
 * Creates a new nested collection of clusterized placemarks.
 *
 * @param clusterListener Listener that controls cluster appearance once
 * they are added to the map.
 */
- (nonnull YMKClusterizedPlacemarkCollection *)addClusterizedPlacemarkCollectionWithClusterListener:(nonnull id<YMKClusterListener>)clusterListener;


/**
 * Traverses through the collection with a visitor object. Used for
 * iteration over map objects in the collection.
 */
- (void)traverseWithMapObjectVisitor:(nonnull id<YMKMapObjectVisitor>)mapObjectVisitor;


/**
 * Removes the given map object from the collection.
 */
- (void)removeWithMapObject:(nonnull YMKMapObject *)mapObject;


/**
 * Removes all map objects from the collection.
 */
- (void)clear;


/**
 * Adds a listener to track notifications of changes to the collection.
 */
- (void)addListenerWithCollectionListener:(nonnull id<YMKMapObjectCollectionListener>)collectionListener;


/**
 * A styler for all placemarks in this collection, including placemarks
 * in child collections.
 */
- (nonnull YMKPlacemarksStyler *)placemarksStyler;


@end

