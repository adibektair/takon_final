#import <YandexMapKit/YMKProjection.h>

#import <yandex/maps/mapkit/geometry/geo/projection.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace geometry {
namespace geo {
namespace ios {

class ProjectionBinding : public ::yandex::maps::mapkit::geometry::geo::Projection {
public:
    explicit ProjectionBinding(
        id<YMKProjection> platformListener);

    virtual ::yandex::maps::mapkit::geometry::geo::XYPoint worldToXY(
        const ::yandex::maps::mapkit::geometry::Point& geoPoint,
        int zoom) const override;

    virtual ::yandex::maps::mapkit::geometry::Point xyToWorld(
        const ::yandex::maps::mapkit::geometry::geo::XYPoint& xyPoint,
        int zoom) const override;

    id<YMKProjection> platformReference() const { return platformListener_; }

private:
    __weak id<YMKProjection> platformListener_;
};

} // namespace ios
} // namespace geo
} // namespace geometry
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>, id<YMKProjection>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection> from(
        id<YMKProjection> platformProjection);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection> from(
        PlatformType platformProjection)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>, id<YMKProjection>>::from(
            platformProjection);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>> {
    static id<YMKProjection> from(
        const std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>& nativeProjection);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
