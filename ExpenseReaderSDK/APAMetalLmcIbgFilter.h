//
//  APAMetalLmcIbgFilter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 05.12.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAMetalFilter.h"

@interface APAMetalLmcIbgFilter : APAMetalFilter
#if !TARGET_OS_SIMULATOR
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                        inputTexture:(APAMetalTexture *)inputTexture
                          kernelSize:(uint)kernelSize
                       kernelOverlap:(uint)kernelOverlap;
#endif
@end
