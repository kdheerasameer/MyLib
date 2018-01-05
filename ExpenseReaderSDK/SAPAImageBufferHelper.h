//
//  SAPAImageBufferHelper.h
//  Algorithm Prototypes
//
//  Created by Venkatesh KRISHNA KUMAR on 8/17/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef SAPAImageBufferHelper_h
#define SAPAImageBufferHelper_h

#include <stdbool.h>
#include "SAPACoordinateHelper.h"
#include "SAPATypes.h"

extern sSAPAImageBuffer SAPAImageBufferMake(void *data, size_t height, size_t width, size_t rowBytes);
extern sSAPAImageBuffer SAPAImageBufferZero();
extern size_t SAPAImageBufferSizeInBytes(sSAPAImageBuffer *buffer);
extern size_t SAPAImageBufferSizeInPixels(sSAPAImageBuffer *buffer, int bytesPerPixel);
extern void SAPAImageBufferAllocateOrReallocateBufferIfNeeded(sSAPAImageBuffer *newBuffer, sSAPABitmapSize bitmapSize, int bytesPerPixel);
extern void SAPAImageBufferAllocateOrReallocateBufferIfNeededWithNtotal(sSAPAImageBuffer *newBuffer, sSAPABitmapSize bitmapSize, int Ntotal, int bytesPerPixel);
extern sSAPAImageBuffer SAPAImageBufferNewWithBitmapSize(sSAPABitmapSize bitmapSize, int bytesPerPixel);
extern sSAPAImageBuffer SAPAImageBufferNewWithBitmapSizeWithNtotal(sSAPABitmapSize bitmapSize, int Ntotal, int bytesPerPixel);
extern void SAPAImageBufferFree(sSAPAImageBuffer *matrix);
extern void SAPAImageBufferCopyBuffer(sSAPAImageBuffer *dst, sSAPAImageBuffer *src);

extern inline sSAPABitmapSize SAPABitmapSizeFromImageBufferWithOrientation(sSAPAImageBuffer *imageBuffer, SAPAImageOrientation imageOrientation);
extern sSAPABitmapSize SAPAbitmapSizeFromImageBuffer(sSAPAImageBuffer* imageBuffer);
extern int SAPANtotalFromImageBuffer(sSAPAImageBuffer* imageBuffer, int bytesPerPixel);
  
// image filters
extern sSAPABitmapSize SAPABitmapSizeForFilterMapSourceImage(sSAPAImageBuffer *source);
extern sSAPABitmapSize SAPABitmapSizeForFilterMap(sSAPAImageBuffer *source);

extern sSAPABitmapSize SAPABitmapSizeRoundedToIntegerMultiple(sSAPABitmapSize bitmapSize, int k);
  
extern void SAPAFilterIsBackgroundMapFromStdMap(sSAPAImageBuffer *isBackgroundMap, sSAPAImageBuffer *stdMap, float threshold, float belowThresholdValue, float aboveThresholdValue);
extern void SAPAFilterTileBasedStandardDeviationMap(sSAPAImageBuffer *stdMap, sSAPAImageBuffer *meanMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform, int kernelOverlap, int kMapSize, int kWindowSize, bool isColor);

extern void SAPAFilterLightMap(sSAPAImageBuffer *lightMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterBinarizationThresholdMap(sSAPAImageBuffer *thresholdMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterLightMapImproved(sSAPAImageBuffer *lightMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern float SAPAFilterOtsuThresholdFromHistogram(float *histogram);
extern void SAPAFilterTileBasedOtsuThresholdMap(sSAPAImageBuffer *thresholdMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform, int kernelOverlap);
extern void SAPAFilterBinarizationUsingThresholdMap(sSAPAImageBuffer *filtered, sSAPAImageBuffer *thresholdMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterBinarization(sSAPAImageBuffer *filtered, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterGrayLMCUsingLightMap(sSAPAImageBuffer *filtered, sSAPAImageBuffer *lightMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterGrayLMC(sSAPAImageBuffer *filtered, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterRGBLMCUsingLightMap(sSAPAImageBuffer *filtered, sSAPAImageBuffer *lightMap, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
extern void SAPAFilterRGBLMC(sSAPAImageBuffer *filtered, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
  
extern void SAPAFilterSauvolaBinarization(sSAPAImageBuffer *filtered, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform);
  
extern void SAPAFilterSimpleBinarization(sSAPAImageBuffer *filtered, sSAPAImageBuffer *source, SAPAColorTransform sourceColorTransform, float threshold);
  

#endif /* SAPAImageBufferHelper_h */

#ifdef __cplusplus
}
#endif
