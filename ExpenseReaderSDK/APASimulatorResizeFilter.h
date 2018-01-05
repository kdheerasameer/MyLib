//
//  APASimulatorResizeFilter.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 14/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APASimulatorFilter.h"

@interface APASimulatorResizeFilter : APASimulatorFilter

- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                        inputTexture:(APASimulatorTexture *)inputTexture
                          outputSize:(sSAPABitmapSize)outputSize;

@end
