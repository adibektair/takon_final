#import <YandexMapKit/YMKConflictResolutionMode.h>
#import <YandexMapKit/YMKSublayerFeatureType.h>

@class YMKSublayerFeatureFilter;

/**
 * Describes a collection of objects on the map that will be rendered
 * together.
 */
@interface YMKSublayer : NSObject

/**
 * The sublayer is a part of the tiled layer or independent map object
 * collection. All features in the same sublayer are rendered together.
 *
 * All layers are listed in this table (G - Ground, M - Models, P -
 * Placemarks, L - Labels):
 *
 * | layer name      | G | M | P | L | description
 * |
 * ------------------------------------------------------------------------|
 * | map             | + |   | + | + | main map layer
 * | | personalizedPoi | + |   | + |   | personalized POI layer
 * | | jams            | + |   | + |   | traffic layer
 * | | carparks        | + |   | + |   | car park layer
 * | | transport       |   |   | + |   | transport object collection
 * | | searchPins      |   |   | + |   | search pins collection
 * | | advertPins      |   |   | + |   | advert pins on the route
 * | | buildings       |   | + |   |   | buildings and models from all
 * layers | |                 |   |   |   |   | (except textured models)
 * | | mapObjects      | + | + | + |   | default map object layer
 * | | userLocation    | + | + | + |   | user location layer
 * |
 * ------------------------------------------------------------------------|
 * | user layer      | + |   | + | + | any new user layer
 * | | collection      | + | + | + |   | any new map object layer
 * |
 */
@property (nonatomic, nonnull) NSString *layerId;

/**
 * Describes the type of features stored in this sublayer.
 */
@property (nonatomic) YMKSublayerFeatureType featureType;

/**
 * Determines how features of the sublayer participates in label
 * conflict resolution.
 */
@property (nonatomic) YMKConflictResolutionMode modeAgainstLabels;

/**
 * Determines how features of the sublayer participates in placemark
 * conflict resolution.
 */
@property (nonatomic) YMKConflictResolutionMode modeAgainstPlacemarks;

/**
 * Sublayer filter. The default filter excludes nothing.
 */
@property (nonatomic, readonly, nonnull) YMKSublayerFeatureFilter *filter;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

