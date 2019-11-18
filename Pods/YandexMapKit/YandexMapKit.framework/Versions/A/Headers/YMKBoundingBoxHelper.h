#import <Foundation/Foundation.h>
#import <YandexMapKit/YMKPolyline.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKBoundingBox.h>
#import <YandexMapKit/YMKLinearRing.h>
#import <YandexMapKit/YMKPolygon.h>

#import <YandexRuntime/YRTExtern.h>

YRT_EXTERN YMKBoundingBox* YMKGetPointBounds(YMKPoint* point);
YRT_EXTERN YMKBoundingBox* YMKGetPolylineBounds(YMKPolyline* polyline);
YRT_EXTERN YMKBoundingBox* YMKGetLinearRingBounds(YMKLinearRing* ring);
YRT_EXTERN YMKBoundingBox* YMKGetPolygonBounds(YMKPolygon* polygon);
