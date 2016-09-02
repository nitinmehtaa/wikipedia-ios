#import <Foundation/Foundation.h>

@class WMFZeroConfiguration;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const WMFIsZeroRatedChanged;
extern NSString *const WMFZeroOnDialogShownOnce;
extern NSString *const WMFZeroWarnWhenLeaving;

@interface WMFZeroConfigurationManager : NSObject

@property (nonatomic, strong, nullable, readonly) WMFZeroConfiguration *zeroConfiguration;

/**
 *  Whether or not the user is on a Wikipedia-Zero-rated network.
 */
@property (atomic, readonly) BOOL isZeroRated;

/**
 *  Whether or not the user prefers to see a modal alert before going to a non-zero-rated URL (i.e. off of Wikipedia).
 */
@property (nonatomic) BOOL warnWhenLeaving;

/**
 * Inspects response headers to determine if network is Zero rated. Sets "isZeroRated" to YES if so or NO if not.
 * Posts WMFIsZeroRatedChanged notification if change is made to "isZeroRated".
 */
- (void)inspectResponseForZeroHeaders:(NSURLResponse*)response;

@end

NS_ASSUME_NONNULL_END
