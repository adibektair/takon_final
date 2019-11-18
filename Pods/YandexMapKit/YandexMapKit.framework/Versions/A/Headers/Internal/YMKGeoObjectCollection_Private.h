#import <YandexMapKit/YMKGeoObjectCollection.h>

#import <YandexRuntime/YRTCollection.h>

#import <yandex/maps/mapkit/geo_object_collection.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_native_fwd.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/bindings/ios/to_platform_fwd.h>

#import <type_traits>



namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::GeoObjectCollection::Item, id, void> {
    static ::yandex::maps::mapkit::GeoObjectCollection::Item from(
        id platformItem);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::GeoObjectCollection::Item, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, id>::value>::type> {
    static ::yandex::maps::mapkit::GeoObjectCollection::Item from(
        PlatformType platformItem)
    {
        return ToNative<::yandex::maps::mapkit::GeoObjectCollection::Item, id>::from(
            platformItem);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::GeoObjectCollection::Item> {
    static id from(
        const ::yandex::maps::mapkit::GeoObjectCollection::Item& item);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
