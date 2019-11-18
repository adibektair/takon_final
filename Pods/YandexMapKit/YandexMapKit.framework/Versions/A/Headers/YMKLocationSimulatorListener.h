#import <Foundation/Foundation.h>

/**
 * Listens for updates for location simulation.
 */
@protocol YMKLocationSimulatorListener <NSObject>

/**
 * Simulation is finished.
 */
- (void)onSimulationFinished;


@end
