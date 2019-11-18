#import <YandexMapKit/YMKIndoorStateListener.h>

#import <yandex/maps/mapkit/indoor_layer/indoor_layer.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace indoor_layer {
namespace ios {

class IndoorStateListenerBinding : public ::yandex::maps::mapkit::indoor_layer::IndoorStateListener {
public:
    explicit IndoorStateListenerBinding(
        id<YMKIndoorStateListener> platformListener);

    virtual void onActivePlanFocused(
        std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorPlan>& activePlan) override;

    virtual void onActivePlanLeft() override;

    id<YMKIndoorStateListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKIndoorStateListener> platformListener_;
};

} // namespace ios
} // namespace indoor_layer
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener>, id<YMKIndoorStateListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener> from(
        id<YMKIndoorStateListener> platformIndoorStateListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener> from(
        PlatformType platformIndoorStateListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener>, id<YMKIndoorStateListener>>::from(
            platformIndoorStateListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener>> {
    static id<YMKIndoorStateListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::indoor_layer::IndoorStateListener>& nativeIndoorStateListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
