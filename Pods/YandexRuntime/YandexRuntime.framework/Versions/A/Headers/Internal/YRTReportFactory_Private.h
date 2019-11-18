#import <YandexRuntime/YRTReportFactory.h>

#import <yandex/maps/runtime/recording/report_data.h>

#import <memory>

@interface YRTReportFactory ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::recording::ReportFactory>&)native;

- (std::shared_ptr<::yandex::maps::runtime::recording::ReportFactory>)nativeReportFactory;
- (std::shared_ptr<::yandex::maps::runtime::recording::ReportFactory>)native;

@end
