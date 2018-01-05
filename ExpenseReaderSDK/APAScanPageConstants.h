//
//  APAScanPageConstans.h
//  Algorithm Prototypes
//
//  Created by Swagat PARIDA on 05/12/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#ifndef APAScanPageConstants_h
#define APAScanPageConstants_h

typedef NS_ENUM(NSInteger, nAPAPageRotation) {
  /** page is not rotated */
  nAPAPageRotationNone,
  /** page is rotated 90° CCW */
  nAPAPageRotationCCW90,
  /** page is rotated 180° CCW */
  nAPAPageRotationCCW180,
  /** page is rotated 270° CCW */
  nAPAPageRotationCCW270,
};
typedef NS_ENUM(NSInteger, nAPAImageFilter) {
  nAPAImageFilterNoFilter,
  nAPAImageFilterRgbLmcFilter,
  nAPAImageFilterGrayLmcFilter,
  nAPAImageFilterGrayLmcBinariztionFilter,
};

@interface APAScanPageConstants : NSObject

+ (NSString*)getRotationAsString:(NSInteger) rotation;
+ (NSInteger)getRotationValue:(NSString*) rotation;
+ (NSInteger)getFilterIndexFromFilterName:(NSString*) filterName;
+ (float)getRotationValueInRadians:(nAPAPageRotation)rotation;
/** image type: source image */
extern NSString const *kAPAFilterPipelineImageTypeSource;
/** image type: cropped image with no filter */
extern NSString const *kAPAFilterPipelineImageTypeNoFilter;
/** image type: cropped image with RGB LMC filter */
extern NSString const *kAPAFilterPipelineImageTypeRgbLmc;
/** image type: cropped image with gray LMC filter */
extern NSString const *kAPAFilterPipelineImageTypeGrayLmc;
/** image type: cropped image with gray LMC binarization filter */
extern NSString const *kAPAFilterPipelineImageTypeGrayLmcBinarization;
/** image type: light map (based on cropped image) */
extern NSString const *kAPAFilterPipelineImageTypeLightMapDictionary;


@end



#endif /* APAScanPageConstants_h */
