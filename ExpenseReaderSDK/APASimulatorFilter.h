//
//  APASimulatorFilter.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 14/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APASimulatorTexture.h"

@interface APASimulatorFilter : NSObject

- (instancetype)initWithFunctionName:(NSString *)functionName;
- (void)applyFilterWithOutputTexture:(APASimulatorTexture *)outputTexture
                        inputTexture:(APASimulatorTexture *)inputTexture;

@end
