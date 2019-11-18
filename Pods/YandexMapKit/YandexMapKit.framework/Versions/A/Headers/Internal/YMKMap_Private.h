#import <YandexMapKit/YMKMap.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/map/map.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

Map::OnMoveFinished onMoveFinished(
    YMKMapCameraCallback handler);

} // namespace ios
} // namespace map
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKMap ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::Map>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::Map>)nativeMap;
- (std::shared_ptr<::yandex::maps::mapkit::map::Map>)native;

@end
