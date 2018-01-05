//
//  APASimulatorFilterTwoInputs.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 14/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APASimulatorFilter.h"
#import "APASimulatorTexture.h"

@interface APASimulatorFilterTwoInputs : NSObject

- (instancetype)initWithFunctionName:(NSString *)functionName;
- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                       inputTexture1:(APASimulatorTexture *)inputTexture1
                       inputTexture2:(APASimulatorTexture *)inputTexture2;

@end
