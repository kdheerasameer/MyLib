//
//  APAImageProcessingHelperMetal.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 27.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import "APAImageProcessingHelper.h"
#import "APAMetalTexture.h"

@interface APAImageProcessingHelperMetal : APAImageProcessingHelper

- (void)createLetterboxResizedTexture:(APAMetalTexture *)resizedTexture
                        sourceTexture:(APAMetalTexture *)sourceTexture
                            letterbox:(sSAPABitmapSize)letterbox
                       doAntiAliasing:(BOOL)doAntiAliasing;
- (void)createCroppedTexture:(APAMetalTexture *)croppedTexture
               sourceTexture:(APAMetalTexture *)sourceTexture
                frameCorners:(sSAPAFrameCorners)frameCorners letterbox:(sSAPABitmapSize)letterbox;

- (void)createLMCLightMapTexture:(APAMetalTexture *)lightMapTexture
                   sourceTexture:(APAMetalTexture *)sourceTexture
                             bgR:(uint8_t *)bgRout bgG:(uint8_t *)bgGout bgB:(uint8_t *)bgBout;
- (void)createGrayLMCFilteredTexture:(APAMetalTexture *)filteredTexture
                       sourceTexture:(APAMetalTexture *)sourceTexture;
- (void)createGrayLMCFilteredTexture:(APAMetalTexture *)filteredTexture
                       sourceTexture:(APAMetalTexture *)sourceTexture
                     lightMapTexture:(APAMetalTexture *)lightMapTexture
                                 bgR:(uint8_t)bgR bgG:(uint8_t)bgG bgB:(uint8_t)bgB;
- (void)createRGBLMCFilteredTexture:(APAMetalTexture *)filteredTexture
                      sourceTexture:(APAMetalTexture *)sourceTexture;
- (void)createRGBLMCFilteredTexture:(APAMetalTexture *)filteredTexture
                      sourceTexture:(APAMetalTexture *)sourceTexture
                    lightMapTexture:(APAMetalTexture *)lightMapTexture
                                bgR:(uint8_t)bgR bgG:(uint8_t)bgG bgB:(uint8_t)bgB;

- (void)createBinarizationThresholdMapTexture:(APAMetalTexture *)thresholdMapTexture
                                sourceTexture:(APAMetalTexture *)sourceTexture;
- (void)createBinarizationFilteredTexture:(APAMetalTexture *)filteredTexture
                            sourceTexture:(APAMetalTexture *)sourceTexture;
- (void)createBinarizationFilteredTexture:(APAMetalTexture *)filteredTexture
                            sourceTexture:(APAMetalTexture *)sourceTexture
                      thresholdMapTexture:(APAMetalTexture *)thresholdMapTexture;
@end
