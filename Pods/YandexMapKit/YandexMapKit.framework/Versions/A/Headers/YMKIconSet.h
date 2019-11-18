#import <UIKit/UIKit.h>

/**
 * A set of icons.
 */
@interface YMKIconSet : NSObject

/**
 * Adds an image to the icon set. The image provider's ID will be used
 * as the icon ID. The image size is scaled using the formula "value =
 * scaleFactor / 4". The same ID should be used as the image-url in the
 * customized layer style.
 */
- (void)addWithImage:(nonnull UIImage *)image;


/**
 * Adds the image with the given ID to the icon source. The image size
 * is scaled using the formula "value = scaleFactor / 4". The same ID
 * should be used as the image-url in the customized layer style.
 */
- (void)addWithId:(nonnull NSString *)id
            image:(nonnull UIImage *)image;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

