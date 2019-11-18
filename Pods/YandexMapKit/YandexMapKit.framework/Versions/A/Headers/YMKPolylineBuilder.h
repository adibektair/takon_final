#import <Foundation/Foundation.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKPoint.h>

@interface YMKPolylineBuilder : NSObject

- (YMKPolylineBuilder *)init;
- (void) appendPolyline:(YMKPolyline *)polyline;
- (void) appendPoint:(YMKPoint *)point;
- (YMKPolyline *)build;

@end
