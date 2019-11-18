#import <YandexMapKit/YMKOverzoomMode.h>

/**
 * Options that are used when adding a layer to the map.
 */
@interface YMKLayerOptions : NSObject

/**
 * Inactive layers are not displayed on the map and do not request any
 * tiles from TileProvider.
 */
@property (nonatomic, assign) BOOL active;

/**
 * Indicates the availability of night mode for this layer (for example,
 * night mode is disabled for the satellite layer). Default: true.
 */
@property (nonatomic, assign) BOOL nightModeAvailable;

/**
 * Determines whether tiles are cached on persistent storage or not.
 */
@property (nonatomic, assign) BOOL cacheable;

/**
 * Indicates whether layer activation should be animated.
 */
@property (nonatomic, assign) BOOL animateOnActivation;

/**
 * Whether to render tiles from adjacent zoom levels in place of absent
 * or translucent tiles.
 */
@property (nonatomic, assign) YMKOverzoomMode overzoomMode;

+ (nonnull YMKLayerOptions *)layerOptionsWithActive:( BOOL)active
                                 nightModeAvailable:( BOOL)nightModeAvailable
                                          cacheable:( BOOL)cacheable
                                animateOnActivation:( BOOL)animateOnActivation
                                       overzoomMode:( YMKOverzoomMode)overzoomMode;


@end

