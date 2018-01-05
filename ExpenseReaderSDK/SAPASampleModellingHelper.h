//
//  SAPASampleModellingHelper.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 23/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPASampleModellingHelper_h
#define SAPASampleModellingHelper_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "SAPACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"
#include "SAPATypes.h"


extern sSAPARansacLineParams *SAPARANSACLinearModelling(sSAPAImageBuffer *xBuffer,
                                                        sSAPAImageBuffer *yBuffer,
                                                        const float maxRansacModelDistance,
                                                        const int iterations,
                                                        bool bIncludeInlierInfo);

extern sSAPAVector2 SAPASolveLinearEquation2x2(sSAPAMatrix2 A, sSAPAVector2 b);

extern sSAPALineEquation SAPALeastSquareLineFit(sSAPAImageBuffer *xBuffer,
                                                sSAPAImageBuffer *yBuffer,
                                                float *labelBuffer,
                                                float bestInlierCount);

extern void SAPASubPixelFit3x3(sSAPAImageBuffer *sourceImage,
                               sSAPAImageBuffer *inputBuffer,
                               sSAPABitmapSize bitmapSize);

#endif /* SAPASampleModellingHelper_h */

#ifdef __cplusplus
}
#endif