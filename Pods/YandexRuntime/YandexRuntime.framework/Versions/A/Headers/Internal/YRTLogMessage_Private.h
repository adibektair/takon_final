#import <YandexRuntime/YRTLogMessage.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/logging/subscription_logger.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::runtime::logging::LogMessage, YRTLogMessage, void> {
    static ::yandex::maps::runtime::logging::LogMessage from(
        YRTLogMessage* platformLogMessage);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::runtime::logging::LogMessage, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTLogMessage*>::value>::type> {
    static ::yandex::maps::runtime::logging::LogMessage from(
        PlatformType platformLogMessage)
    {
        return ToNative<::yandex::maps::runtime::logging::LogMessage, YRTLogMessage>::from(
            platformLogMessage);
    }
};

template <>
struct ToPlatform<::yandex::maps::runtime::logging::LogMessage> {
    static YRTLogMessage* from(
        const ::yandex::maps::runtime::logging::LogMessage& logMessage);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
