#import <YandexMapKit/YMKResourceUrlProvider.h>

#import <yandex/maps/mapkit/resource_url_provider/resource_url_provider.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace resource_url_provider {
namespace ios {

class ResourceUrlProviderBinding : public ::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider {
public:
    explicit ResourceUrlProviderBinding(
        id<YMKResourceUrlProvider> platformListener);

    virtual std::string formatUrl(
        const std::string& resourceId) const override;

    id<YMKResourceUrlProvider> platformReference() const { return platformListener_; }

private:
    __weak id<YMKResourceUrlProvider> platformListener_;
};

} // namespace ios
} // namespace resource_url_provider
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider>, id<YMKResourceUrlProvider>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider> from(
        id<YMKResourceUrlProvider> platformResourceUrlProvider);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider> from(
        PlatformType platformResourceUrlProvider)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider>, id<YMKResourceUrlProvider>>::from(
            platformResourceUrlProvider);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider>> {
    static id<YMKResourceUrlProvider> from(
        const std::shared_ptr<::yandex::maps::mapkit::resource_url_provider::ResourceUrlProvider>& nativeResourceUrlProvider);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
