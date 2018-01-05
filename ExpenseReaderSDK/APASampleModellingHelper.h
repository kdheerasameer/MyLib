//
//  APASampleModellingHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 05/07/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImageBufferHelper.h"
#include "SAPASampleModellingHelper.h"


@interface APASampleModellingHelper : NSObject

+ (sSAPARansacLineParams *)RANSACLinearModelling:(sSAPAImageBuffer *)xBuffer
                                           yData:(sSAPAImageBuffer *)yBuffer
                                maxModelDistance:(const float)maxRansacModelDistance
                                      iterations:(const int)iterations
                              bIncludeInlierInfo:(BOOL)bIncludeInlierInfo
                                         useVDSP:(BOOL)useVDSP;
+ (sSAPALineEquation)leastSquareLineFit:(sSAPAImageBuffer *)xBuffer
                                  yData:(sSAPAImageBuffer *)yBuffer
                            sampleLabel:(float *)labelBuffer
                            inlierCount:(float)bestInlierCount
                                useVDSP:(BOOL)useVDSP;
+ (sSAPALineEquation)leastSquareLineFit:(sSAPAImageBuffer *)xBuffer
                                  yData:(sSAPAImageBuffer *)yBuffer
                       bestLineEquation:(sSAPALineEquation)bestLineEquation
                            sampleLabel:(float *)labelBuffer
                            inlierCount:(float)bestInlierCount
                            maxDistance:(float)maxDistance
                                useVDSP:(BOOL)useVDSP;
+ (void)subPixelFit3x3:(sSAPAImageBuffer *)sourceImage
           inputBuffer:(sSAPAImageBuffer *)inputBuffer
            bitmapSize:(sSAPABitmapSize)bitmapSize;

@end
