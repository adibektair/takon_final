#import <YandexMapKit/YMKLogo.h>

#import <yandex/maps/mapkit/logo/logo.h>

#import <memory>

@interface YMKLogo ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::logo::Logo>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::logo::Logo>)nativeLogo;
- (std::shared_ptr<::yandex::maps::mapkit::logo::Logo>)native;

@end
