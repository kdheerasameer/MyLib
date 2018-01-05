//
//  APACoordinateHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 16/05/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import <Accelerate/Accelerate.h>
#import "APAColorTransformConverter.h"
#include "SAPACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"

/*!
 * Holds all result info of a frame tracking test run
 */
typedef struct _sAPAFrameTrackingTestResult {
  int totalItems;
  int confirmedGroundTruthItems;
  int successCount;
  float successPercentage;
  float totalDuration;
  float itemDuration;
} sAPAFrameTrackingTestResult;

/*!
 * Holds all result info of a frame detection test run
 */
typedef struct _sAPAFrameDetectionTestResult {
  int totalItems;
  int confirmedGroundTruthItems;
  int successCount;
  float successPercentage;
  float totalDuration;
  float itemDuration;
} sAPAFrameDetectionTestResult;

@interface APACoordinateHelper : NSObject

// shared type conversion
+ (CGPoint)cgPointFromSAPAPoint:(sSAPAPoint)point;
+ (sSAPAPoint)sapaPointFromCGPoint:(CGPoint)point;
+ (sSAPASize)sapaSizeFromCGSize:(CGSize)size;
+ (SAPAImageOrientation)imageOrientationFromUIImageOrientation:(UIImageOrientation)uiImageOrientation;

// transform between pixel and image coordinates
+ (CGAffineTransform)pixelToImageCGAffineTransformImageSize:(sSAPAImageSize)imageSize bitmapSize:(sSAPABitmapSize)bitmapSize;
+ (CGAffineTransform)imageToPixelCGAffineTransformImageSize:(sSAPAImageSize)imageSize bitmapSize:(sSAPABitmapSize)bitmapSize;
+ (sSAPABitmapSize)bitmapSizeFromCGSize:(CGSize)cgSize;
+ (CGSize)CGSizeFromBitmapSize:(sSAPABitmapSize)bitmapSize;
+ (sSAPAMatrix3)metalPixelToPixelFromSapa:(sSAPAMatrix3)pixelToPixel;

// transform between cartesian and polar coordinates

// JSON parser helper
+ (NSString *)stringFromFrameCorners:(sSAPAFrameCorners)corners;
+ (sSAPAFrameCorners)getFrameCornersFromJsonDict:(NSDictionary *)dict;
+ (NSDictionary *)getJsonDictFromFrameCorners:(sSAPAFrameCorners)corners;
+ (sSAPAFrameCorners)transformOldJSONframeToImageCoordinatesFrame:(sSAPAFrameCorners)oldCorners; // TODO: old, remove

+ (sSAPAFrameTrackingConfiguration)frameTrackingConfigurationFromJsonDict:(NSDictionary *)dict;
+ (NSDictionary *)jsonDictFromFrameTrackingConfiguration:(sSAPAFrameTrackingConfiguration)config;
+ (sAPAFrameTrackingTestResult)frameTrackingTestResultFromJsonDict:(NSDictionary *)dict;
+ (NSDictionary *)jsonDictFromFrameTrackingTestResult:(sAPAFrameTrackingTestResult)result;

+ (sSAPAFrameDetectionConfiguration)frameDetectionConfigurationFromJsonDict:(NSDictionary *)dict;
+ (NSDictionary *)jsonDictFromFrameDetectionConfiguration:(sSAPAFrameDetectionConfiguration)config;
+ (sAPAFrameDetectionTestResult)frameDetectionTestResultFromJsonDict:(NSDictionary *)dict;
+ (NSDictionary *)jsonDictFromFrameDetectionTestResult:(sAPAFrameDetectionTestResult)result;


// frame corners
#warning TODO: isCornersVisible has a strange interface, remove if possible
+ (BOOL)isCornersVisible:(sSAPAFrameCorners)corners M:(int)M N:(int)N;


@end
