//
//  APAImageProcessingHelperSimulator.h
//  ExpenseReaderSDKDemo
//
//  Created by Suresh YERVA on 14/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import "APAImageProcessingHelper.h"
#import "APASimulatorTexture.h"

@interface APAImageProcessingHelperSimulator : APAImageProcessingHelper
- (void)createLetterboxResizedTexture:(APASimulatorTexture *)resizedTexture
                        sourceTexture:(APASimulatorTexture *)sourceTexture
                            letterbox:(sSAPABitmapSize)letterbox
                       doAntiAliasing:(BOOL)doAntiAliasing;
- (void)createCroppedTexture:(APASimulatorTexture *)croppedTexture
               sourceTexture:(APASimulatorTexture *)sourceTexture
                frameCorners:(sSAPAFrameCorners)frameCorners letterbox:(sSAPABitmapSize)letterbox;

- (void)createLMCLightMapTexture:(APASimulatorTexture *)lightMapTexture
                   sourceTexture:(APASimulatorTexture *)sourceTexture
                             bgR:(uint8_t *)bgRout bgG:(uint8_t *)bgGout bgB:(uint8_t *)bgBout;
- (void)createGrayLMCFilteredTexture:(APASimulatorTexture *)filteredTexture
                       sourceTexture:(APASimulatorTexture *)sourceTexture;
- (void)createGrayLMCFilteredTexture:(APASimulatorTexture *)filteredTexture
                       sourceTexture:(APASimulatorTexture *)sourceTexture
                     lightMapTexture:(APASimulatorTexture *)lightMapTexture
                                 bgR:(uint8_t)bgR bgG:(uint8_t)bgG bgB:(uint8_t)bgB;
- (void)createRGBLMCFilteredTexture:(APASimulatorTexture *)filteredTexture
                      sourceTexture:(APASimulatorTexture *)sourceTexture;
- (void)createRGBLMCFilteredTexture:(APASimulatorTexture *)filteredTexture
                      sourceTexture:(APASimulatorTexture *)sourceTexture
                    lightMapTexture:(APASimulatorTexture *)lightMapTexture
                                bgR:(uint8_t)bgR bgG:(uint8_t)bgG bgB:(uint8_t)bgB;

- (void)createBinarizationThresholdMapTexture:(APASimulatorTexture *)thresholdMapTexture
                                sourceTexture:(APASimulatorTexture *)sourceTexture;
- (void)createBinarizationFilteredTexture:(APASimulatorTexture *)filteredTexture
                            sourceTexture:(APASimulatorTexture *)sourceTexture;
- (void)createBinarizationFilteredTexture:(APASimulatorTexture *)filteredTexture
                            sourceTexture:(APASimulatorTexture *)sourceTexture
                      thresholdMapTexture:(APASimulatorTexture *)thresholdMapTexture;
@end
