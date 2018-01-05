//
//  APAMetalGrayLMCNewMapFilter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 05.12.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAMetalFilterTwoInputs.h"

@interface APAMetalGrayLMCNewMapFilter : APAMetalFilterTwoInputs
#if !TARGET_OS_SIMULATOR
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                       inputTexture1:(APAMetalTexture *)inputTexture1
                       inputTexture2:(APAMetalTexture *)inputTexture2
                                 bgR:(uint8_t)bgR
                                 bgG:(uint8_t)bgG
                                 bgB:(uint8_t)bgB;
#endif
@end
