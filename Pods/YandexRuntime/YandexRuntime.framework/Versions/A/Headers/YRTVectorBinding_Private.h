#pragma once

#import <Foundation/Foundation.h>

#include <yandex/maps/runtime/bindings/vector_cb.h>

#include <memory>

@interface YRTVectorBinding : NSArray

-(id)initWithNativeObject:(std::unique_ptr<yandex::maps::runtime::bindings::internal::VectorCbBase>)nativeObject;
-(yandex::maps::runtime::bindings::internal::VectorCbBase *)getNativeObject;

@end
