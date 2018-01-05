//
//  SAPAFrameTrackingHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 25/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAFrameTrackingHelper_h
#define SAPAFrameTrackingHelper_h

#include <stdio.h>
#include "SAPACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"
#include "SAPAColorTransformHelper.h"
#include "SAPAImageWarpHelper.h"

sSAPAEdgeImageScores SAPAGetFrameEdgeImageScores(sSAPAFrameCorners frameCorners, SAPAColorTransform colorTransform, SAPAColorTransform sourceColorTransform, sSAPAImageBuffer *sourceBgra, sSAPAColorTransformConverter *edgeCTconverter, sSAPAFrameTrackingConfiguration config);
sSAPAFrameCorners getFrameTrackedCorners(sSAPAFrameCorners frameCorners, SAPAColorTransform colorTransform,
                                         sSAPAImageBuffer *sourceBgra, SAPAImageOrientation sourceOrientation, sSAPAColorTransformConverter *edgeCTconverter,sSAPAFrameTrackingConfiguration config);

#endif /* SAPAFrameTrackingHelper_h */

#ifdef __cplusplus
}
#endif