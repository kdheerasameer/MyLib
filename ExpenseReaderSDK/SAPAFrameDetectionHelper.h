//
//  SAPAFrameDetectionHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 30/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAFrameDetectionHelper_h
#define SAPAFrameDetectionHelper_h

#include <stdio.h>
#include "SAPAColorTransformHelper.h"
#include "SAPACoordinateHelper.h"
#include "SAPATypes.h"

extern void SAPAResetKernelCache(sSAPAFDManagerParams* fdManagerParams);
extern void SAPACreateEdgeKernelsIfNeeded(sSAPAFDManagerParams* fdManagerParams);
extern void SAPAComputeObjectiveFunction(sSAPAFDManagerParams* fdManagerParams, sSAPAImageBuffer *objFunc, sSAPAImageBuffer *fdSourceTransformed);
extern void SAPANonMaximumSuppression(sSAPAImageBuffer *image, sSAPAImageBuffer *nonMaxImage, const int R);
extern void SAPAMaximaList(sSAPAImageBuffer *maximaList, sSAPAImageBuffer *image, sSAPAImageBuffer *maxImage, const int maxMaximaCount, const float acceptableMaximumThreshold);
extern void SAPAConstructMaximaLines(sSAPAImageBuffer* maximaList, sSAPABitmapSize objFuncSize, sSAPABitmapSize fdSourceBitmapSize, sSAPAPolar* bestPhiRho, sSAPALineEquation* maximaLines);
extern void SAPASortLinesbyAngle(sSAPALineEquation *maximaLines, sSAPAPolar *bestPhiRho, const int maxCount);
extern void SAPAFindBestPolarCoordinates(sSAPAFDManagerParams* fdManagerParams, sSAPAImageBuffer *objFunc, sSAPAImageBuffer *bestPolarCoordinatesBuffer, int algoStepIndex, sSAPAImageBuffer *outputBuffer);
extern void SAPAComputeBestFrameForColorTransform(sSAPAFDManagerParams* fdManagerParams, sSAPAImageBuffer *bestPhiRhoBuffer, sSAPAImageBuffer *sourceBgra, SAPAColorTransform colorTransform, SAPAColorTransform sourceColorTransform, sSAPAFrameCorners *currentBestFrameCorners, float *currentBestFrameScore);
extern void SAPARunFDForCurrentColorTransform(sSAPAFDManagerParams* fdManagerParams, SAPAColorTransform colorTransform, SAPAColorTransform sourceColorTransform, sSAPAImageBuffer *sourceImageBig, SAPAImageOrientation sourceOrientation, float *bestFrameScore, sSAPAFrameCorners *bestFrameCorners, sSAPAImageBuffer **fdSourceTransformed, bool mode, int algoStepIndex, sSAPAImageBuffer *outputBuffer, sSAPAImageBuffer *externalFtSourceImage);
extern sSAPAFrameCorners SAPAFDManagerDetectFrame(SAPAColorTransform sourceColorTransform, sSAPAImageBuffer *sourceImageBig, SAPAImageOrientation sourceOrientation, sSAPAFrameDetectionConfiguration fdConfig, sSAPAFrameTrackingConfiguration ftConfig, sSAPAFDManagerParams* fdManagerParams);

#endif /* SAPAFrameDetectionHelper_h */

#ifdef __cplusplus
}
#endif