#import <Foundation/Foundation.h>

@class YMKCluster;

@protocol YMKClusterListener <NSObject>

/**
 * This method is called when a new cluster is added to the collection
 * and should customize cluster appearance based on its content.
 */
- (void)onClusterAddedWithCluster:(nonnull YMKCluster *)cluster;


@end
