#import <Foundation/Foundation.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKSubpolyline.h>

#import <YandexRuntime/YRTExtern.h>

YRT_EXTERN YMKPolyline* YMKMakeSubpolyline(YMKPolyline* polyline, YMKSubpolyline* subpolyline);
YRT_EXTERN double YMKSubpolylineLength(YMKPolyline* polyline, YMKSubpolyline* subpolyline);
