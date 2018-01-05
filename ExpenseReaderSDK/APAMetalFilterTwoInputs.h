//
//  APAMetalFilterTwoInputs.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 26.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>

#if !TARGET_OS_SIMULATOR
#import <Metal/Metal.h>
#endif

#import "APAMetalTexture.h"


@interface APAMetalFilterTwoInputs : NSObject
#if !TARGET_OS_SIMULATOR
@property (nonatomic, strong) id<MTLBuffer> uniformBuffer;
@property (nonatomic, strong) id<MTLComputePipelineState> pipeline;

- (instancetype)initWithFunctionName:(NSString *)functionName;
- (void)applyFilterWithOutputTexture:(APAMetalTexture *)outputTexture
                       inputTexture1:(APAMetalTexture *)inputTexture1
                       inputTexture2:(APAMetalTexture *)inputTexture2;
#endif
@end

