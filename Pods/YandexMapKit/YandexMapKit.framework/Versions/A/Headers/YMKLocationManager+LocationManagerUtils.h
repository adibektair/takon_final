#import <YandexMapKit/YMKLocation.h>
#import <YandexMapKit/YMKLocationManager.h>

@interface YMKLocationManager (LocationManagerUtils)

+ (YMKLocation *)lastKnownLocation;

@end
