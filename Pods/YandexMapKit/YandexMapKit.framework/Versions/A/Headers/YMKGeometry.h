#import <YandexMapKit/YMKBoundingBox.h>
#import <YandexMapKit/YMKCircle.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKPolygon.h>
#import <YandexMapKit/YMKPolyline.h>

@interface YMKGeometry : NSObject

@property (nonatomic, readonly, nullable) YMKPoint *point;

@property (nonatomic, readonly, nullable) YMKPolyline *polyline;

@property (nonatomic, readonly, nullable) YMKPolygon *polygon;

@property (nonatomic, readonly, nullable) YMKBoundingBox *boundingBox;

@property (nonatomic, readonly, nullable) YMKCircle *circle;

+ (nonnull YMKGeometry *)geometryWithPoint:(nonnull YMKPoint *)point;

+ (nonnull YMKGeometry *)geometryWithPolyline:(nonnull YMKPolyline *)polyline;

+ (nonnull YMKGeometry *)geometryWithPolygon:(nonnull YMKPolygon *)polygon;

+ (nonnull YMKGeometry *)geometryWithBoundingBox:(nonnull YMKBoundingBox *)boundingBox;

+ (nonnull YMKGeometry *)geometryWithCircle:(nonnull YMKCircle *)circle;

@end

