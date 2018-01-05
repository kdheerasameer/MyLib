//
//  SAPAEdgeDetectionKernelHelper.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 29/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAEdgeDetectionKernelHelper_h
#define SAPAEdgeDetectionKernelHelper_h

#include <stdio.h>
#include <math.h>
#include "SAPAImageBufferHelper.h"

extern void SAPACreateDenseBuffer(sSAPAImageBuffer *denseImage,
                                  sSAPABitmapSize bitmapSize,
                                  int nTotal,
                                  sSAPAImageBuffer *sparsePosition,
                                  sSAPAImageBuffer *sparseValue);

extern void SAPAArrangeSparseBuffer(sSAPAImageBuffer *denseImage,
                                    sSAPAImageBuffer *sparsePosition,
                                    sSAPAImageBuffer *sparseValue);

extern void SAPAArrangeSparseBufferNonZero(sSAPAImageBuffer *denseImage,
                                           sSAPAImageBuffer *sparsePosition,
                                           sSAPAImageBuffer *sparseValue,
                                           float nonZeroCount);

extern void SAPACreateEdgeDetectionKernelSparsePosition(sSAPAImageBuffer *sparsePosition,
                                                        sSAPAImageBuffer *sparseValue,
                                                        sSAPAPolar line,
                                                        float sigmaX,
                                                        float sigmaY,
                                                        float nonZeroThreshold,
                                                        sSAPABitmapSize bitmapSize);

#endif /* SAPAEdgeDetectionKernelHelper_h */

#ifdef __cplusplus
}
#endif