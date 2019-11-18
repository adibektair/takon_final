#pragma once

#import <Foundation/Foundation.h>

#include <yandex/maps/runtime/bindings/dictionary_cb.h>
#include <yandex/maps/runtime/bindings/ios/dictionary_key_enumerator.h>

#include <memory>

@interface YRTStringDictionaryBinding : NSDictionary

-(id)initWithNativeObject:(std::unique_ptr<yandex::maps::runtime::bindings::internal::StringDictionaryCbBase>)nativeObject;
-(yandex::maps::runtime::bindings::internal::StringDictionaryCbBase *)getNativeObject;

@end

@interface YRTStringDictionaryKeyEnumeratorBinding : NSEnumerator

-(id)initWithNativeObject:(std::unique_ptr<yandex::maps::runtime::bindings::ios::internal::StringDictionaryKeyEnumeratorBase>)nativeObject;

@end
