//
//  APAMoirePatternDetection.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 03/11/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPAImageBufferHelper.h"
#include "SAPAMoirePatternDetection.h"

/*!
 * Holds all result info of a Moire pattern test run
 */
typedef struct _sAPAMoirePatternTestResult {
  int totalItems;
  int confirmedGroundTruthItems;
  int successCount;
  float successPercentage;
  float totalDuration;
  float itemDuration;
} sAPAMoirePatternTestResult;

@interface APAMoirePatternDetection : NSObject

+ (float)APAGetHighFreqStdScore:(sSAPAImageBuffer *)inputImage debugImage:(sSAPAImageBuffer*)debugImage params:(sSAPAMoireParams)params;
- (SAPAMoireDetectionResult)APAIsMoirePatternPresent:(sSAPAImageBuffer*)inputImage debugImage:(sSAPAImageBuffer*)debugImage params:(sSAPAMoireParams*)params;
- (SAPAMoireDetectionResult)APAIsMoirePatternPresent:(CVImageBufferRef)inputImage params:(sSAPAMoireParams)params;
+ (NSDictionary *)jsonDictFromMoirePatternTestResult:(sAPAMoirePatternTestResult)result;
+ (NSDictionary *)jsonDictFromMoirePatternConfiguration:(sSAPAMoireParams)config;
+ (sSAPAMoireParams)moireConfigurationFromJsonDict:(NSDictionary *)dict;
+ (sAPAMoirePatternTestResult)moireTestResultFromJsonDict:(NSDictionary *)dict;


@end
