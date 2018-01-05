//
//  APAImageProcessingHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 27.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "SAPATypes.h"

@interface APAImageProcessingHelper : NSObject

// image warping
- (void)createCroppedImage:(UIImage **)croppedImage sourceImage:(UIImage **)sourceImage
              frameCorners:(sSAPAFrameCorners)frameCorners letterbox:(sSAPABitmapSize)letterbox;

// LMC / shading removal
- (void)createLMCLightMap:(UIImage **)lightMap sourceImage:(UIImage **)sourceImage;
- (void)createGrayLMCFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage;
- (void)createGrayLMCFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage lightMap:(UIImage **)lightMap;
- (void)createRGBLMCFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage;
- (void)createRGBLMCFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage lightMap:(UIImage **)lightMap;

// binarization
- (void)createBinarizationThresholdMap:(UIImage **)thresholdMap sourceImage:(UIImage **)sourceImage;
- (void)createBinarizationFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage;
- (void)createBinarizationFilteredImage:(UIImage **)filteredImage sourceImage:(UIImage **)sourceImage thresholdMap:(UIImage **)thresholdMap;

// internal / to be moved to a private helper
+ (void)createBinarizationThresholdMap:(sSAPAImageBuffer *)thresholdMap
                                source:(sSAPAImageBuffer *)source
                  sourceColorTransform:(SAPAColorTransform)sourceColorTransform;


@end

