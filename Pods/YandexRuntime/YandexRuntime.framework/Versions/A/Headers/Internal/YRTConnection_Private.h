#import <YandexRuntime/YRTConnection.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/rpc/internal/connection.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace rpc {
namespace internal {
namespace ios {

class ConnectionBinding : public ::yandex::maps::runtime::rpc::internal::Connection {
public:
    explicit ConnectionBinding(
        id<YRTConnection> platformListener);

    virtual bool connect(
        std::unique_ptr<::yandex::maps::runtime::rpc::Client> client,
        ::yandex::maps::runtime::rpc::ConnectionStateListener* l) override;

    virtual void disconnect() override;

    virtual ::yandex::maps::runtime::rpc::SendDataResult sendData(
        const std::vector<std::uint8_t>& data) override;

    id<YRTConnection> platformReference() const { return platformListener_; }

private:
    id<YRTConnection> platformListener_;
};

} // namespace ios
} // namespace internal
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
struct ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection>, id<YRTConnection>, void> {
    static std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection> from(
        id<YRTConnection> platformConnection);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection> from(
        PlatformType platformConnection)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection>, id<YRTConnection>>::from(
            platformConnection);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection>> {
    static id<YRTConnection> from(
        const std::shared_ptr<::yandex::maps::runtime::rpc::internal::Connection>& nativeConnection);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
