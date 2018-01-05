//
//  EdgeDetectionKernelHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 19/05/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>
#import "APACoordinateHelper.h"

@interface EdgeDetectionKernelHelper : NSObject

+ (void)createDenseBuffer:(sSAPAImageBuffer *)denseImage bitmapSize:(sSAPABitmapSize)bitmapSize nTotal:(int)nTotal fromSparsePosition:(sSAPAImageBuffer *)sparsePosition sparseValue:(sSAPAImageBuffer *)sparseValue;
//+ (void)createEdgeDetectionKernelSparsePosition:(sSAPAImageBuffer*)sparsePosition sparseValue:(sSAPAImageBuffer*)sparseValue phi:(float)phi rho:(float)rho sigmaX:(float)sigmaX sigmaY:(float)sigmaY nonZeroTreshold:(float)nonZeroThreshold bitmapSize:(sSAPABitmapSize)bitmapSize;

+ (void)createEdgeDetectionKernelImageBufferNOVDSP:(sSAPAImageBuffer *)imageBuffer phi:(float)phi rho:(float)rho sigmaX:(float)sigmaX sigmaY:(float)sigmaY nonZeroTreshold:(float)nonZeroThreshold bitmapSize:(sSAPABitmapSize)bitmapSize;
/*
+ (void)createEdgeDetectionKernelImageBuffer:(sSAPAImageBuffer *)imageBuffer kerPosList:(sSAPAImageBuffer*)kerPosList kerValList:(sSAPAImageBuffer*)kerValList  phi:(float)phi rho:(float)rho sigmaX:(float)sigmaX sigmaY:(float)sigmaY nonZeroTreshold:(float)nonZeroThreshold bitmapSize:(sAPABitmapSize)bitmapSize;
 */

+ (void)createEdgeDetectionKernelSparsePosition:(sSAPAImageBuffer*)sparsePosition sparseValue:(sSAPAImageBuffer*)sparseValue line:(sSAPAPolar)line sigmaX:(float)sigmaX sigmaY:(float)sigmaY nonZeroTreshold:(float)nonZeroThreshold bitmapSize:(sSAPABitmapSize)bitmapSize;

@end
