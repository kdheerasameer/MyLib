//
//  SAPAMoirePatternDetection.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 26/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#ifndef SAPAMoirePatternDetection_h
#define SAPAMoirePatternDetection_h

#include <stdio.h>
#include "SAPATypes.h"

extern float SAPAstdDevScore(sSAPAImageBuffer* LLImage,
                             sSAPAImageBuffer* LHBuffer,
                             sSAPAImageBuffer* HLBuffer,
                             sSAPAImageBuffer* HHBuffer,
                             sSAPAMoireParams params,
                             int ignoreBorder);
extern void SAPASplitFreqBands(sSAPAImageBuffer* inputImage,
                               sSAPAImageBuffer* LLBuffer,
                               sSAPAImageBuffer* LHBuffer,
                               sSAPAImageBuffer* HLBuffer,
                               sSAPAImageBuffer* HHBuffer,
                               sSAPAMoireParams params);
extern float SAPAGetHighFreqStdScore(sSAPAImageBuffer* inputImage, sSAPAImageBuffer* tempImage, const sSAPAMoireParams params);
extern SAPAMoireDetectionResult isMoirePatternPresent(sSAPAImageBuffer* inputImage, sSAPAImageBuffer* tempImage, sSAPAMoireParams params);
extern sSAPAMoireParams SAPAGetDefaultMoireParams();

#endif /* SAPAMoirePatternDetection_h */
