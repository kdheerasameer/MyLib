//
//  SAPAColorTransformHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 23/08/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAColorTransformHelper_h
#define SAPAColorTransformHelper_h

#include <stdio.h>
#include "SAPAImageBufferHelper.h"
#include "SAPATypes.h"

extern sSAPAColorTransformConverter SAPAColorTransformConverterNew();

extern void SAPAColorTransformConverterFree(sSAPAColorTransformConverter *converter);

extern void SAPAColorTransformConverterResetCache(sSAPAColorTransformConverter *converter);

extern sSAPAImageBuffer *
SAPAColorTransformFunc(sSAPAColorTransformConverter *converter, SAPAColorTransform colorTransform);

extern void SAPAColorTransformConverterWriteColorBuffer(sSAPAColorTransformConverter *converter,
                                                        sSAPAImageBuffer *externalColorBuffer,
                                                        SAPAColorTransform sourceColorTransform);

extern sSAPAImageBuffer *
SAPAColorTransformConverterColorBufferForExternalWriting(sSAPAColorTransformConverter *converter,
                                                         SAPAColorTransform sourceColorTransform);

extern void SAPAColorTransformConverterResetCacheAndMarkColorBufferAsCached(
        sSAPAColorTransformConverter *converter, SAPAColorTransform sourceColorTransform);

#endif /* SAPAColorTransformHelper_h */

#ifdef __cplusplus
}
#endif