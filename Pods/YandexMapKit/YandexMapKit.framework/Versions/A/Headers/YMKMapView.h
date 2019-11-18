#import <YandexMapKit/YMKMapWindow.h>

#import <UIKit/UIKit.h>

@interface YMKMapView : UIView

@property (nonatomic, readonly) YMKMapWindow *mapWindow;
- (void)setNoninteractive:(bool)is;

@end
