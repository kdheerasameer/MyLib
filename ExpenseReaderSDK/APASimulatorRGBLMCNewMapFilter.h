//
//  APASimulatorRGBLMCNewMapFilter.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 15/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APASimulatorFilterTwoInputs.h"

@interface APASimulatorRGBLMCNewMapFilter : APASimulatorFilterTwoInputs

- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                       inputTexture1:(APASimulatorTexture *)inputTexture1
                       inputTexture2:(APASimulatorTexture *)inputTexture2
                                 bgR:(uint8_t)bgR
                                 bgG:(uint8_t)bgG
                                 bgB:(uint8_t)bgB;

@end
