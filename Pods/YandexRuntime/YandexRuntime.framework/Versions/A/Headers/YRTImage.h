#import <UIKit/UIKit.h>

@interface UIImage (YRTImage)

/**
 * Determines whether image should be cached on GPU or not. 
 */
@property (nonatomic) BOOL yrtCacheable;

@end