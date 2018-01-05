//
//  SAPAEdgeTrackingHelper.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 17/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdlib.h>
#include "SAPACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"
#include "SAPASampleModellingHelper.h"

extern float SAPAedgeImageScoreOfEdgeImage(sSAPAImageBuffer *edgeImage);

extern void
SAPAapplyHorizontalEdgeFilter(sSAPAImageBuffer *filteredBuffer, sSAPAImageBuffer *edgeImageBuffer);

extern void SAPAfindShortestPath(sSAPAImageBuffer *graph,
                                 sSAPAImageBuffer *filteredBuffer,
                                 sSAPABitmapSize bitmapSize,
                                 int Ntotal,
                                 sSAPAImageBuffer *outputBuffer,
                                 int outputID,
                                 sSAPAImageBuffer *pointListBuffer,
                                 int pointListID,
                                 float *edgePoints,
                                 int *totalPointCount);

extern void
SAPAedgePointClassification(sSAPAImageBuffer *filteredBuffer, sSAPAImageBuffer *tempBuffer,
                            float edgePointMaxFactor);

extern sSAPALineEquation SAPAFitLineToEdgeImage(sSAPAImageBuffer *edgeImageBuffer,
                                                sSAPAImageBuffer *outputBuffer,
                                                int outputID,
                                                sSAPAImageBuffer *pointListBuffer,
                                                int pointListID,
                                                float ransacInlierDistance,
                                                float edgePointMaxFactor);

extern sSAPALineEquation SAPAFitLineToEdgeImageWithRANSACInlier(sSAPAImageBuffer *edgeImageBuffer,
                                                                float ransacInlierDistance,
                                                                float edgePointMaxFactor);

extern sSAPALineEquation SAPAFitLineToEdgeImageWithOutputBuffer(sSAPAImageBuffer *edgeImageBuffer,
                                                                sSAPAImageBuffer *outputBuffer,
                                                                int outputID);

#ifndef SAPAEdgeTrackingHelper_h
#define SAPAEdgeTrackingHelper_h


#endif /* SAPAEdgeTrackingHelper_h */

#ifdef __cplusplus
}
#endif