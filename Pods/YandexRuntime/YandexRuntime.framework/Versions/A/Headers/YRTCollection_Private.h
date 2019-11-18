#import <YandexRuntime/YRTCollection.h>

#include <yandex/maps/runtime/any/collection.h>

#include <memory>

using yandex::maps::runtime::any::Collection;

@interface YRTCollection ()

- (id)initWithNativeObject:(std::shared_ptr<Collection>)nativeObject;

- (std::shared_ptr<Collection>)getNativeObject;

@end
