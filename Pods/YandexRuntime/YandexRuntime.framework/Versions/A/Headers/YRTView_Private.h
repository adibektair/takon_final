#import <UIKit/UIKit.h>
#import <YandexRuntime/YRTTouchEvent_Private.h>

#include <yandex/maps/runtime/view/platform_view.h>

@protocol YRTViewFactory;

@interface YRTView : UIView

- (id)initWithFrame:(CGRect)frame scale:(float)scale;
- (id)initWithFrame:(CGRect)frame;
- (yandex::maps::runtime::view::PlatformView*)getPlatformView;
- (void)setNoninteractive:(bool)is;
- (void)handleTouchEvent:(YRTTouchEvent *)touchEvent;

- (void)deinitialize;

@end
