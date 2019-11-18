#import <YandexRuntime/YRTLogListener.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/logging/subscription_logger.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace logging {
namespace ios {

class LogListenerBinding : public ::yandex::maps::runtime::logging::LogListener {
public:
    explicit LogListenerBinding(
        id<YRTLogListener> platformListener);

    virtual void onMessageRecieved(
        const ::yandex::maps::runtime::logging::LogMessage& message) override;

    id<YRTLogListener> platformReference() const { return platformListener_; }

private:
    __weak id<YRTLogListener> platformListener_;
};

} // namespace ios
} // namespace logging
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
struct ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, id<YRTLogListener>, void> {
    static std::shared_ptr<::yandex::maps::runtime::logging::LogListener> from(
        id<YRTLogListener> platformLogListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::logging::LogListener> from(
        PlatformType platformLogListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, id<YRTLogListener>>::from(
            platformLogListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>> {
    static id<YRTLogListener> from(
        const std::shared_ptr<::yandex::maps::runtime::logging::LogListener>& nativeLogListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
