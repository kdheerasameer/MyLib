//
//  APASimulatorWarpFilter.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 14/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APASimulatorFilter.h"

@interface APASimulatorWarpFilter : APASimulatorFilter

- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                        inputTexture:(APASimulatorTexture *)inputTexture
                        frameCorners:(sSAPAFrameCorners)frameCorners;

@end
