#import <YandexMapKit/YMKMapObjectVisitor.h>

#import <yandex/maps/mapkit/map/map_object_visitor.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class MapObjectVisitorBinding : public ::yandex::maps::mapkit::map::MapObjectVisitor {
public:
    explicit MapObjectVisitorBinding(
        id<YMKMapObjectVisitor> platformListener);

    virtual void onPlacemarkVisited(
        ::yandex::maps::mapkit::map::PlacemarkMapObject* placemark) override;

    virtual void onPolylineVisited(
        ::yandex::maps::mapkit::map::PolylineMapObject* polyline) override;

    virtual void onColoredPolylineVisited(
        ::yandex::maps::mapkit::map::ColoredPolylineMapObject* polyline) override;

    virtual void onPolygonVisited(
        ::yandex::maps::mapkit::map::PolygonMapObject* polygon) override;

    virtual void onCircleVisited(
        ::yandex::maps::mapkit::map::CircleMapObject* circle) override;

    virtual bool onCollectionVisitStart(
        ::yandex::maps::mapkit::map::MapObjectCollection* collection) override;

    virtual void onCollectionVisitEnd(
        ::yandex::maps::mapkit::map::MapObjectCollection* collection) override;

    id<YMKMapObjectVisitor> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapObjectVisitor> platformListener_;
};

} // namespace ios
} // namespace map
} // namespace mapkit
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor>, id<YMKMapObjectVisitor>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor> from(
        id<YMKMapObjectVisitor> platformMapObjectVisitor);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor> from(
        PlatformType platformMapObjectVisitor)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor>, id<YMKMapObjectVisitor>>::from(
            platformMapObjectVisitor);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor>> {
    static id<YMKMapObjectVisitor> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::MapObjectVisitor>& nativeMapObjectVisitor);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
