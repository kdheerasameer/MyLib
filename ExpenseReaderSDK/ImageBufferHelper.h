//
//  ImageBufferHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 18/05/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>
#import <UIKit/UIKit.h>
#import "APACoordinateHelper.h"
#import "SAPAImageBufferHelper.h"

#warning: TODO:include vs import

@interface ImageBufferHelper : NSObject

// SAPAImageBuffer type conversion
+ (void)vImageBuffer:(vImage_Buffer *)dest fromSAPAImageBuffer:(sSAPAImageBuffer *)source;
+ (void)sapaImageBuffer:(sSAPAImageBuffer *)dest fromVImageBuffer:(vImage_Buffer *)source;
+ (void)sapaImageBuffer:(sSAPAImageBuffer *)dest fromPixelBuffer:(CVImageBufferRef)pixelBuffer;

// Visual debugging
+ (UIImage *)createImageFromFloatImageBuffer:(sSAPAImageBuffer *)imageBuffer useJetColorMap:(BOOL)useJetColorMap centerAroundZero:(BOOL)centerAroundZero;
+ (UIImage *)createImageFromFloatImageBuffer:(sSAPAImageBuffer *)imageBuffer useJetColorMap:(BOOL)useJetColorMap minValue:(float)minValue maxValue:(float)maxValue;

// UIImage, SAPAImageBuffer conversion
+ (void)readBGRAbuffer:(sSAPAImageBuffer *)bgraBuffer fromUIImage:(UIImage *)image;
+ (void)readBGRAbufferNoAlloc:(sSAPAImageBuffer *)bgraBuffer fromUIImage:(UIImage *)image;
+ (UIImage *)createImageFromBgraImageBuffer:(sSAPAImageBuffer *)bgraBuffer;
+ (UIImage *)createImageFromGrayImageBuffer:(sSAPAImageBuffer *)grayBuffer;

@end
