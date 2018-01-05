//
//  APAWaveletTransformHelper.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 03/11/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPAImageBufferHelper.h"

@interface APAWaveletTransformHelper : NSObject

+ (void)APAHaarFWT2D:(sSAPAImageBuffer *)inputImg level:(int)level isColor:(BOOL)isColor;

@end

