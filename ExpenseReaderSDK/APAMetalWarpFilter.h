//
//  APAMetalWarpFilter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 19.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAMetalFilter.h"

@interface APAMetalWarpFilter : APAMetalFilter
#if !TARGET_OS_SIMULATOR
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                        inputTexture:(APAMetalTexture *)inputTexture
                        frameCorners:(sSAPAFrameCorners)frameCorners;
#endif
@end

