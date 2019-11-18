#import <YandexMapKit/YMKCoverageRegionsSession.h>

#import <yandex/maps/mapkit/coverage/regions_session.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace coverage {
namespace ios {

RegionsSession::OnRegionsResponse onRegionsResponse(
    YMKCoverageRegionsSessionResponseHandler handler);
RegionsSession::OnRegionsError onRegionsError(
    YMKCoverageRegionsSessionResponseHandler handler);

} // namespace ios
} // namespace coverage
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKCoverageRegionsSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::coverage::RegionsSession>)native;

- (::yandex::maps::mapkit::coverage::RegionsSession *)nativeRegionsSession;

@end
