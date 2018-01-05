//
//  APAMetalResizeFilter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 15.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAMetalFilter.h"

@interface APAMetalResizeFilter : APAMetalFilter
#if !TARGET_OS_SIMULATOR
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                        inputTexture:(APAMetalTexture *)inputTexture
                          outputSize:(sSAPABitmapSize)outputSize;
#endif
@end

