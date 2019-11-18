#import <YandexRuntime/YRTReportData.h>

#import <yandex/maps/runtime/recording/report_data.h>

#import <memory>

@interface YRTReportData ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::recording::ReportData>&)native;

- (std::shared_ptr<::yandex::maps::runtime::recording::ReportData>)nativeReportData;
- (std::shared_ptr<::yandex::maps::runtime::recording::ReportData>)native;

@end
