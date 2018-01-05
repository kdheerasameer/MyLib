//
//  APAFrameDetectionManager.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 19/06/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIImage+Resize.h"
#import "APACoordinateHelper.h"
#import "APAFrameDetectionHelper.h"

@interface APAFrameDetectionManager : NSObject
- (id)initWithUseShared:(BOOL)useShared;
- (void)resetKernelCache;
- (sSAPAFrameCorners)detectFrame:(UIImage *)sourceImageBig
                          config:(sSAPAFrameDetectionConfiguration)fdConfig;
- (sSAPAFrameCorners)detectFrame:(UIImage *)sourceImageBig config:(sSAPAFrameDetectionConfiguration)fdConfig frameDetectionSuccessful:(BOOL *)frameDetectionSuccessful;
- (sSAPAFrameCorners)detectFrameForCVImageBuffer:(CVImageBufferRef)sourceImagePixelBuffer config:(sSAPAFrameDetectionConfiguration)fdConfig frameDetectionSuccessful:(BOOL *)frameDetectionSuccessful;
- (sSAPAFrameCorners)trackFrameForCVImageBuffer:(CVImageBufferRef)sourceImagePixelBuffer frameCorners:(sSAPAFrameCorners)frameCorners config:(sSAPAFrameDetectionConfiguration)config frameTrackingSuccessful:(BOOL *)frameTrackingSuccessful;

- (void)runFDForCurrentColorTransform:(SAPAColorTransform)colorTransform
                             srcImage:(UIImage *)sourceImageBig
                               config:(sSAPAFrameDetectionConfiguration)fdConfig
                       bestFrameScore:(float *)bestFrameScore
                     bestFrameCorners:(sSAPAFrameCorners *)bestFrameCorners
                  fdSourceTransformed:(sSAPAImageBuffer **)fdSourceTransformed
               allColorTransformsMode:(BOOL)mode
                        algoStepIndex:(int)algoStepIndex
                           tempBuffer:(sSAPAImageBuffer *)outputBuffer;

- (void)runFDForCurrentColorTransformForSAPAImageBuffer:(SAPAColorTransform)colorTransform
                                               srcImage:(sSAPAImageBuffer)fdResizedImageBuffer
                                                 config:(sSAPAFrameDetectionConfiguration)fdConfig
                                         bestFrameScore:(float *)bestFrameScore
                                       bestFrameCorners:(sSAPAFrameCorners *)bestFrameCorners
                                    fdSourceTransformed:(sSAPAImageBuffer **)fdSourceTransformed
                                 allColorTransformsMode:(BOOL)mode
                                          algoStepIndex:(int)algoStepIndex
                                             tempBuffer:(sSAPAImageBuffer *)outputBuffer;

- (sSAPAFrameCorners*)trackedFrameCorners;

@end
