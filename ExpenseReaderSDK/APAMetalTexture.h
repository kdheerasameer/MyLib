//
//  APAMetalTexture.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 19.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAImageBuffer.h"

@interface APAMetalTexture : APAImageBuffer

@property (nonatomic, strong) id<MTLTexture> texture;

@end
