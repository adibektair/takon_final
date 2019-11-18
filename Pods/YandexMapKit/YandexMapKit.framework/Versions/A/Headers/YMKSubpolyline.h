#import <YandexMapKit/YMKPolylinePosition.h>

/**
 * A part of a polyline.
 */
@interface YMKSubpolyline : NSObject

/**
 * The start of the selected part of the polyline.
 */
@property (nonatomic, readonly, nonnull) YMKPolylinePosition *begin;

/**
 * The end of the selected part of the polyline.
 */
@property (nonatomic, readonly, nonnull) YMKPolylinePosition *end;


+ (nonnull YMKSubpolyline *)subpolylineWithBegin:(nonnull YMKPolylinePosition *)begin
                                             end:(nonnull YMKPolylinePosition *)end;


@end

