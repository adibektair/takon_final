#import <YandexRuntime/YRTNativeObject.h>

typedef YRTNativeObject* (^YRTListenerFactory)(id);

@interface YRTSubscription : NSObject

- (id)initWithKey:(void*)key factory:(YRTListenerFactory)factory; 
- (YRTNativeObject *)getAssociatedWith:(id)listener;

@end
