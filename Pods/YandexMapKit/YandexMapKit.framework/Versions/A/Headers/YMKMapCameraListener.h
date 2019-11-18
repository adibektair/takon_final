#import <YandexMapKit/YMKCameraPosition.h>
#import <YandexMapKit/YMKCameraUpdateSource.h>

@class YMKMap;

/**
 * Listens for updates to the camera position.
 */
@protocol YMKMapCameraListener <NSObject>

/**
 * Triggered when the camera position changed.
 *
 * @param map New map area.
 * @param cameraPosition Current camera position.
 * @param cameraUpdateSource Previous camera position.
 * @param finished True if the camera finished moving, false otherwise.
 */
- (void)onCameraPositionChangedWithMap:(nonnull YMKMap *)map
                        cameraPosition:(nonnull YMKCameraPosition *)cameraPosition
                    cameraUpdateSource:(YMKCameraUpdateSource)cameraUpdateSource
                              finished:(BOOL)finished;


@end
