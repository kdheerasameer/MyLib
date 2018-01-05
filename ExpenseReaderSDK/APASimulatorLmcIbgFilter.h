//
//  APASimulatorLmcIbgFilter.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 15/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APASimulatorFilter.h"

@interface APASimulatorLmcIbgFilter : APASimulatorFilter

- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                        inputTexture:(APASimulatorTexture *)inputTexture
                          kernelSize:(uint)kernelSize
                       kernelOverlap:(uint)kernelOverlap;

@end
