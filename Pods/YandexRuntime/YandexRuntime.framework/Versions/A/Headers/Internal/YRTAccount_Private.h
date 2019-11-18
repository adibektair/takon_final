#import <YandexRuntime/YRTAccount.h>

#import <yandex/maps/runtime/auth/account.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace auth {
namespace ios {

class AccountBinding : public ::yandex::maps::runtime::auth::Account {
public:
    explicit AccountBinding(
        id<YRTAccount> platformListener);

    virtual std::string uid() override;

    virtual void requestToken(
        std::unique_ptr<::yandex::maps::runtime::auth::TokenListener> tokenListener) override;

    virtual void invalidateToken(
        const std::string& token) override;

    virtual boost::optional<std::string> httpAuth(
        const std::string& token) override;

    id<YRTAccount> platformReference() const { return platformListener_; }

private:
    id<YRTAccount> platformListener_;
};

} // namespace ios
} // namespace auth
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
struct ToNative<std::shared_ptr<::yandex::maps::runtime::auth::Account>, id<YRTAccount>, void> {
    static std::shared_ptr<::yandex::maps::runtime::auth::Account> from(
        id<YRTAccount> platformAccount);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::auth::Account>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::auth::Account> from(
        PlatformType platformAccount)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::auth::Account>, id<YRTAccount>>::from(
            platformAccount);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::auth::Account>> {
    static id<YRTAccount> from(
        const std::shared_ptr<::yandex::maps::runtime::auth::Account>& nativeAccount);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
