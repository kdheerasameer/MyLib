//
//  SAPAImageWarpHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 21/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAImageWarpHelper_h
#define SAPAImageWarpHelper_h

#include <stdio.h>
#include <stdbool.h>
#include "SAPAImageBufferHelper.h"
#include "SAPATypes.h"

extern sSAPAMatrix3 SAPAHomographyFromDstPixelsToSrcPixels(sSAPABitmapSize dstBitmapSize,
                                                           sSAPABitmapSize srcBitmapSize,
                                                           sSAPAFrameCorners frameCorners,
                                                           SAPAImageOrientation srcOrientation);

#warning TODO: rename ImageBufferWarp(ed) or similar
extern void SAPACreateWarpedImage(sSAPAImageBuffer *warpedColorBuffer, sSAPAImageBuffer *sourceColorBuffer, SAPAImageOrientation sourceOrientation, sSAPAFrameCorners frameCorners, sSAPABitmapSize warpedBitmapSize);

extern void SAPAImageBufferResize(sSAPAImageBuffer *resizedColorBuffer, sSAPAImageBuffer *sourceColorBuffer, SAPAImageOrientation sourceOrientation, sSAPABitmapSize newBitmapSize, bool doAntiAliasing);


#endif /* SAPAImageWarpHelper_h */

#ifdef __cplusplus
}
#endif
