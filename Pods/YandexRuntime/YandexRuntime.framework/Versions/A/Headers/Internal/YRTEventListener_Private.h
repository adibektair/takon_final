#import <YandexRuntime/YRTEventListener.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/recording/event_logging.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace recording {
namespace ios {

class EventListenerBinding : public ::yandex::maps::runtime::recording::EventListener {
public:
    explicit EventListenerBinding(
        id<YRTEventListener> platformListener);

    virtual void onEvent(
        const std::string& event,
        const std::shared_ptr<::yandex::maps::runtime::bindings::StringDictionary<std::string>>& data) override;

    virtual void onValue(
        const std::string& name,
        double value) override;

    id<YRTEventListener> platformReference() const { return platformListener_; }

private:
    __weak id<YRTEventListener> platformListener_;
};

} // namespace ios
} // namespace recording
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, id<YRTEventListener>, void> {
    static std::shared_ptr<::yandex::maps::runtime::recording::EventListener> from(
        id<YRTEventListener> platformEventListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::recording::EventListener> from(
        PlatformType platformEventListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, id<YRTEventListener>>::from(
            platformEventListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>> {
    static id<YRTEventListener> from(
        const std::shared_ptr<::yandex::maps::runtime::recording::EventListener>& nativeEventListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
