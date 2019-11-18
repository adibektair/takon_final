#import <Foundation/Foundation.h>

/**
 * Provides resource URLs for other classes.
 */
@protocol YMKResourceUrlProvider <NSObject>

/**
 * Generates a URL that is used to load a resource based on its ID.
 */
- (nonnull NSString *)formatUrlWithResourceId:(nonnull NSString *)resourceId;


@end
