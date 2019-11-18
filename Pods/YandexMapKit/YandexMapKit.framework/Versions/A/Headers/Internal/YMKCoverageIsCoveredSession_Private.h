#import <YandexMapKit/YMKCoverageIsCoveredSession.h>

#import <yandex/maps/mapkit/coverage/is_covered_session.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace coverage {
namespace ios {

IsCoveredSession::OnCoveredResponse onCoveredResponse(
    YMKCoverageIsCoveredSessionResponseHandler handler);
IsCoveredSession::OnCoveredError onCoveredError(
    YMKCoverageIsCoveredSessionResponseHandler handler);

} // namespace ios
} // namespace coverage
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKCoverageIsCoveredSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::coverage::IsCoveredSession>)native;

- (::yandex::maps::mapkit::coverage::IsCoveredSession *)nativeIsCoveredSession;

@end
