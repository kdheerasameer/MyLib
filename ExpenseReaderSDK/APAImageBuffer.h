//
//  APAImageBuffer.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 13.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "SAPATypes.h"

@interface APAImageBuffer : NSObject

@property (assign, readonly) UIImageOrientation imageOrientation;

- (instancetype)initWithBitmapSize:(sSAPABitmapSize)bitmapSize;
- (instancetype)initWithUIImage:(UIImage *)image;
- (void)resetWithBitmapSize:(sSAPABitmapSize)bitmapSize;
- (void)resetWithUIImage:(UIImage *)image;
- (void)accessBgraBuffer:(sSAPAImageBuffer *)bgraBuffer readOnly:(BOOL)readOnly;
- (void)stopAccessReadOnly:(BOOL)readOnly;
- (UIImage *)getTextureUIImage;
- (sSAPABitmapSize)bitmapSize;
- (sSAPABitmapSize)bitmapSizeWithImageOrientation;

@end
