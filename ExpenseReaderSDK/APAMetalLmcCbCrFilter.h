//
//  APAMetalLmcCbCrFilter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 05.12.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAMetalFilter.h"

@interface APAMetalLmcCbCrFilter : APAMetalFilter
#if !TARGET_OS_SIMULATOR
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                        inputTexture:(APAMetalTexture *)inputTexture
                      pixelThreshold:(float)pixelThreshold;
#endif
@end

