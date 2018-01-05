//
//  APAFrameDetectionHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 19/06/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImageBufferHelper.h"
#import "APAColorTransformConverter.h"
#include "SAPAImageBufferHelper.h"

@interface APAFrameDetectionHelper : NSObject

+ (BOOL)configIsEqualToConfigWRTKernelCreation:(sSAPAFrameDetectionConfiguration)config1 config2:(sSAPAFrameDetectionConfiguration)config2;
+ (void)nonMaximumSuppression:(sSAPAImageBuffer *)image nonMaxImage:(sSAPAImageBuffer *)nonMaxImage R:(const int)R;
+ (void)nonMaximumSuppression:(sSAPAImageBuffer *)image nonMaxImage:(sSAPAImageBuffer *)nonMaxImage;

+ (void)maximaList:(sSAPAImageBuffer *)maximaList fromImage:(sSAPAImageBuffer *)image maxImage:(sSAPAImageBuffer *)maxImage maxCount:(const int)maxMaximaCount maximumThreshold:(const float)acceptableMaximumThreshold;
+ (void)maximaList:(sSAPAImageBuffer *)maximaList fromImage:(sSAPAImageBuffer *)image maxImage:(sSAPAImageBuffer *)maxImage maxCount:(const int)maxMaximaCount;
+ (void)maximaList:(sSAPAImageBuffer *)maximaList fromImage:(sSAPAImageBuffer *)image maxImage:(sSAPAImageBuffer *)maxImage  maximumThreshold:(const float)acceptableMaximumThreshold;
+ (void)maximaList:(sSAPAImageBuffer *)maximaList fromImage:(sSAPAImageBuffer *)image maxImage:(sSAPAImageBuffer *)maxImage;

+ (void)constructMaximaLines:(sSAPAImageBuffer*)maximaList objFuncSize:(sSAPABitmapSize)objFuncSize fdSourceBitmapSize:(sSAPABitmapSize)fdSourceBitmapSize bestPhiRho:(sSAPAPolar*)bestPhiRho maximaLines:(sSAPALineEquation*)maximaLines;

+ (void)sortLinesbyAngle:(sSAPALineEquation *)maximaLines bestPhiRho:(sSAPAPolar *)bestPhiRho count:(const int)maxCount;
+ (void)sortLinesbyAngle:(sSAPALineEquation *)maximaLines bestPhiRho:(sSAPAPolar *)bestPhiRho;

+ (void)computeObjectiveFunction:(sSAPABitmapSize)objFuncSize sourceBitMapSize:(sSAPABitmapSize)fdSourceBitmapSize objFunc:(sSAPAImageBuffer *)objFunc colorTransformedData:(sSAPAImageBuffer *)fdSourceTransformed sparseKernelPosition:(sSAPAImageBuffer *)cachedSparseKernelPosition sparseKernelValue:(sSAPAImageBuffer *)cachedSparseKernelValue sigmaX:(const float)sigmaX sigmaY:(const float)sigmaY threshold:(const float)nonZeroTreshold;
+ (void)computeObjectiveFunction:(sSAPABitmapSize)objFuncSize sourceBitMapSize:(sSAPABitmapSize)fdSourceBitmapSize objFunc:(sSAPAImageBuffer*)objFunc colorTransformedData:(sSAPAImageBuffer *)fdSourceTransformed sparseKernelPosition:(sSAPAImageBuffer *)_sparseKernelPosition sparseKernelValue:(sSAPAImageBuffer*)_sparseKernelValue;
+ (void)computeObjectiveFunction:(sSAPABitmapSize)objFuncSize sourceBitMapSize:(sSAPABitmapSize)fdSourceBitmapSize objFunc:(sSAPAImageBuffer*)objFunc colorTransformedData:(sSAPAImageBuffer *)fdSourceTransformed sparseKernelPosition:(sSAPAImageBuffer*)_sparseKernelPosition sparseKernelValue:(sSAPAImageBuffer*)_sparseKernelValue halfDiagnolValue:(const float)halfDiagnolVal sigmaX:(const float)sigmaXVal sigmaY:(const float)sigmaYVal;


+ (void)findBestPolarCoordinates:(sSAPAImageBuffer *)objFunc
                     objFuncSize:(sSAPABitmapSize)objFuncSize
              fdSourceBitmapSize:(sSAPABitmapSize)fdSourceBitmapSize
          polarCoordinatesBuffer:(sSAPAImageBuffer *)bestpolarCoordinatesBuffer
                suppresionRadius:(int)nonMaxSuppressionRadius
                       linecount:(int)count
                maximumThreshold:(float)maximumThreshold
                   algoStepIndex:(int)algoStepIndex
                      tempBuffer:(sSAPAImageBuffer *)outputBuffer;

+ (void)findBestPolarCoordinates:(sSAPAImageBuffer *)objFunc
                     objFuncSize:(sSAPABitmapSize)objFuncSize
              fdSourceBitmapSize:(sSAPABitmapSize)fdSourceBitmapSize
          polarCoordinatesBuffer:(sSAPAImageBuffer *)bestpolarCoordinatesBuffer
                suppresionRadius:(int)nonMaxSuppressionRadius
                maximumThreshold:(float)maximumThreshold
                   algoStepIndex:(int)algoStepIndex
                      tempBuffer:(sSAPAImageBuffer *)outputBuffer;

/*
+ (void)findBestPolarCoordinates:(sSAPAImageBuffer *)objFunc
                     objFuncSize:(sSAPABitmapSize)objFuncSize
              fdSourceBitmapSize:(sSAPABitmapSize)fdSourceBitmapSize
          polarCoordinatesBuffer:(sSAPAImageBuffer *)bestpolarCoordinatesBuffer
                       linecount:(int)count
                maximumThreshold:(float)maximumThreshold
                   algoStepIndex:(int)algoStepIndex
                      tempBuffer:(sSAPAImageBuffer *)outputBuffer;
 */

+ (void)findBestPolarCoordinates:(sSAPAImageBuffer *)objFunc
                     objFuncSize:(sSAPABitmapSize)objFuncSize
              fdSourceBitmapSize:(sSAPABitmapSize)fdSourceBitmapSize
          polarCoordinatesBuffer:(sSAPAImageBuffer *)bestpolarCoordinatesBuffer
                   algoStepIndex:(int)algoStepIndex
                maximumThreshold:(float)maximumThreshold
                      tempBuffer:(sSAPAImageBuffer *)outputBuffer;

+ (void)computeBestFrameForColorTransform:(sSAPAImageBuffer *)bestPhiRhoBuffer
                              phiRhoCount:(int)lineCount
                               sourceBgra:(sSAPAImageBuffer *)sourceBgra
                           colorTransform:(SAPAColorTransform)colorTransform
                          edgeCTConverter:(APAColorTransformConverter *)edgeCTConverterObject
                         currentBestFrame:(sSAPAFrameCorners *)currentBestFrameCorners
                    currentBestFrameScore:(float *)currentBestFrameScore
                                  minDiff:(const float)minDiff
                                  maxDiff:(const float)maxDiff;
+ (void)computeBestFrameForColorTransform:(sSAPAImageBuffer *)bestPhiRhoBuffer
                              phiRhoCount:(int)lineCount
                               sourceBgra:(sSAPAImageBuffer *)sourceBgra
                          edgeCTConverter:(APAColorTransformConverter *)edgeCTConverterObject
                         currentBestFrame:(sSAPAFrameCorners *)currentBestFrameCorners
                    currentBestFrameScore:(float *)currentBestFrameScore;
+ (void)computeBestFrameForColorTransform:(sSAPAImageBuffer *)bestPhiRhoBuffer
                              phiRhoCount:(int)lineCount
                               sourceBgra:(sSAPAImageBuffer *)sourceBgra
                           colorTransform:(SAPAColorTransform)colorTransform
                          edgeCTConverter:(APAColorTransformConverter *)edgeCTConverterObject
                         currentBestFrame:(sSAPAFrameCorners *)currentBestFrameCorners
                    currentBestFrameScore:(float *)currentBestFrameScore;
+ (void)computeBestFrameForColorTransform:(sSAPAImageBuffer *)bestPhiRhoBuffer
                              phiRhoCount:(int)lineCount
                               sourceBgra:(sSAPAImageBuffer *)sourceBgra
                          edgeCTConverter:(APAColorTransformConverter *)edgeCTConverterObject
                         currentBestFrame:(sSAPAFrameCorners *)currentBestFrameCorners
                    currentBestFrameScore:(float *)currentBestFrameScore
                                  minDiff:(const float)minDiff
                                  maxDiff:(const float)maxDiff;

+ (sSAPAFrameCorners)trackFrameWithFrame:(sSAPAFrameCorners)detectedFrameCorners
                              sourceBgra:(sSAPAImageBuffer *)sourceBgra
                  sourceImageOrientation:(SAPAImageOrientation)sourceOrientation
                         edgeCTConverter:(APAColorTransformConverter *)edgeCTConverterObject;


@end
