#import <YandexRuntime/YRTServiceClient.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/rpc/service_client.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace rpc {
namespace ios {

class ServiceClientBinding : public ::yandex::maps::runtime::rpc::ServiceClient {
public:
    explicit ServiceClientBinding(
        id<YRTServiceClient> platformListener);

    virtual bool handle(
        const std::vector<std::uint8_t>& data) override;

    virtual std::string clientId() override;

    id<YRTServiceClient> platformReference() const { return platformListener_; }

private:
    id<YRTServiceClient> platformListener_;
};

} // namespace ios
} // namespace rpc
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
struct ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient>, id<YRTServiceClient>, void> {
    static std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient> from(
        id<YRTServiceClient> platformServiceClient);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient> from(
        PlatformType platformServiceClient)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient>, id<YRTServiceClient>>::from(
            platformServiceClient);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient>> {
    static id<YRTServiceClient> from(
        const std::shared_ptr<::yandex::maps::runtime::rpc::ServiceClient>& nativeServiceClient);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
