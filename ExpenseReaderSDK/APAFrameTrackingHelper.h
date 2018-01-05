//
//  APAFrameTrackingHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 02/06/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APACoordinateHelper.h"
#import "APAColorTransformConverter.h"
#include "SAPAImageBufferHelper.h"
#include "SAPAImageWarpHelper.h"


@interface APAFrameTrackingHelper : NSObject

+ (sSAPAEdgeImageScores)getFrameEdgeImageScores:(sSAPAFrameCorners)frameCorners
                                colorTransform:(SAPAColorTransform)colorTransform
                                    sourceBgra:(sSAPAImageBuffer *)sourceBgra
                               edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter;

+ (sSAPAFrameCorners)getFrameTrackedCorners:(sSAPAFrameCorners)frameCorners
                             colorTransform:(SAPAColorTransform)colorTransform
                                 sourceBgra:(sSAPAImageBuffer *)sourceBgra
                            edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter;

+ (sSAPAFrameCorners)getFrameTrackedCorners:(sSAPAFrameCorners)frameCorners
                             colorTransform:(SAPAColorTransform)colorTransform
                                 sourceBgra:(sSAPAImageBuffer *)sourceBgra
                          sourceOrientation:(SAPAImageOrientation)sourceOrientation
                            edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter;

+ (sSAPAEdgeImageScores)getFrameEdgeImageScores:(sSAPAFrameCorners)frameCorners
                                colorTransform:(SAPAColorTransform)colorTransform
                                    sourceBgra:(sSAPAImageBuffer *)sourceBgra
                               edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter
                                        config:(sSAPAFrameTrackingConfiguration)config;

+ (sSAPAFrameCorners)getFrameTrackedCorners:(sSAPAFrameCorners)frameCorners
                             colorTransform:(SAPAColorTransform)colorTransform
                                 sourceBgra:(sSAPAImageBuffer *)sourceBgra
                            edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter
                                     config:(sSAPAFrameTrackingConfiguration)config;

+ (sSAPAFrameCorners)getFrameTrackedCorners:(sSAPAFrameCorners)frameCorners
                             colorTransform:(SAPAColorTransform)colorTransform
                                 sourceBgra:(sSAPAImageBuffer *)sourceBgra
                          sourceOrientation:(SAPAImageOrientation)sourceOrientation
                            edgeCTconverter:(APAColorTransformConverter *)edgeCTconverter
                                     config:(sSAPAFrameTrackingConfiguration)config;

@end
