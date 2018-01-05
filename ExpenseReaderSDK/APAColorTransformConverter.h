//
//  APAIntensityImageConverter.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 23/05/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>
#import <UIKit/UIKit.h>
#include "SAPAImageBufferHelper.h"
#include "SAPAColorTransformHelper.h"

@interface APAColorTransformConverter : NSObject

- (id)initWithUseShared:(BOOL)useShared;
- (void)readBgraBufferFromUIImage:(UIImage *)image;
- (void)readBgraBuffer:(sSAPAImageBuffer *)externalBgraBuffer;
- (sSAPAImageBuffer *)bgraBufferForExternalWriting;
- (void)resetCacheAndMarkBgraBufferAsCached;
- (sSAPAImageBuffer *)colorTransform:(SAPAColorTransform)colorTransform;

@end
