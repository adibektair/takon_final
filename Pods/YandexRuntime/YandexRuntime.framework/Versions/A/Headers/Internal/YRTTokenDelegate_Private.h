#import <YandexRuntime/YRTTokenDelegate.h>

#import <yandex/maps/runtime/auth/account.h>

#import <memory>

@interface YRTTokenDelegate ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::runtime::auth::TokenListener>)native;

- (::yandex::maps::runtime::auth::TokenListener *)nativeTokenListener;

@end
