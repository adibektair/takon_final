#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// @cond EXCLUDE
@interface YRTViewProvider : NSObject {
    BOOL _cacheable;
}

/**
 * True if view provider is cacheable. False otherwise.
 */
@property (nonatomic, readonly) BOOL cacheable;

/**
 * Constructor of YRTViewProvider.
 * Attention!!! Blocks UI via executing snapshot function!
 */
- (id)initWithUIView:(UIView*)view cacheable:(BOOL)cacheable;
/**
 * Constructor of YRTViewProvider. Cacheable flag will have YES value by default.
 * Attention!!! Blocks UI via executing snapshot function!
 */
- (id)initWithUIView:(UIView*)view;
/**
 * Makes snapshot of the given view.
 * Attention!!! Blocks UI!
 */
- (void)snapshot;

@end

/// @endcond