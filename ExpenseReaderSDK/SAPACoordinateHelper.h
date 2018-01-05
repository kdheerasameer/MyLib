//
//  SAPACoordinateHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 16/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef SAPACoordinateHelper_h
#define SAPACoordinateHelper_h
  
#include <stdbool.h>
#include "SAPATypes.h"


// configurations
extern sSAPAFrameTrackingConfiguration SAPADefaultFTConfiguration();
  
// constructors
sSAPAMatrix3 SAPAMatrix3Make(float m11, float m12, float m13,
                             float m21, float m22, float m23,
                             float m31, float m32, float m33);
sSAPAVector3 SAPAVector3Make(float x, float y, float z);
extern sSAPAMatrix2 SAPAMatrix2Make(float m11, float m12,
                                    float m21, float m22);
extern sSAPAVector2 SAPAVector2Make(float x, float y);
sSAPALineEquation SAPALineEquationMake(float a, float b, float c);
extern sSAPAImageSize SAPAImageSizeMake(float w, float h);
extern sSAPASize SAPASizeMake(float width, float height);
extern sSAPABitmapSize SAPABitmapSizeMake(int M, int N);
extern sSAPAPoint SAPAPointMake(float x, float y);
extern sSAPAPolar SAPAPolarMake(float phi, float rho);
extern sSAPAFrameCorners SAPAFrameCornersMake(sSAPAPoint TR, sSAPAPoint TL, sSAPAPoint BL, sSAPAPoint BR, sSAPAImageSize imageSize);
extern sSAPAFrameEdgePoints SAPAFrameEdgePointsMake(sSAPAPoint T, sSAPAPoint L, sSAPAPoint B, sSAPAPoint R);
extern sSAPASize SAPASizeFromBitmapSize(sSAPABitmapSize bitmapSize);
// linear algebra, matrix vector
extern sSAPAMatrix3 SAPAMatrix3Identity();
extern sSAPAMatrix3 SAPAMatrix3Transpose(sSAPAMatrix3 matrix);
extern sSAPAMatrix3 SAPAMatrix3MakeAndTranspose(float m11, float m12, float m13,
                                                float m21, float m22, float m23,
                                                float m31, float m32, float m33);
extern sSAPAVector3 SAPAMatrix3MultiplyVector3(sSAPAMatrix3 m, sSAPAVector3 v);
extern sSAPAMatrix3 SAPAMatrix3Multiply(sSAPAMatrix3 a, sSAPAMatrix3 b);
extern sSAPAVector3 SAPAMatrix3GetColumn(sSAPAMatrix3 a, int columnIndex);
extern float SAPAVector3Length(sSAPAVector3 v);
extern float SAPAMatrix3Determinant(sSAPAMatrix3 a);
extern sSAPAMatrix3 SAPAMatrix3MultiplyScalar(sSAPAMatrix3 a, float s);
extern sSAPAMatrix3 SAPAMatrix3Invert(sSAPAMatrix3 A, bool *invertible);
extern sSAPAVector3 SAPAVector3CrossProduct(sSAPAVector3 a, sSAPAVector3 b);
extern float SAPAVector3DotProduct(sSAPAVector3 a, sSAPAVector3 b);
extern sSAPAVector3 SAPAVector3MultiplyScalar(sSAPAVector3 a, float s);
extern sSAPAVector2 SAPAVector2DivideScalar(sSAPAVector2 vector, float value);
extern sSAPAFrameTrackingConfiguration SAPAdefaultFTConfiguration();
extern sSAPAPoint SAPAPointMapWithHomography(sSAPAPoint p, sSAPAMatrix3 H);
extern sSAPAFrameCorners SAPAFrameCornersMapWithHomography(sSAPAFrameCorners frameCorners, sSAPAMatrix3 H);
extern float SAPAPointDistance(sSAPAPoint pointA, sSAPAPoint pointB);



// transform between pixel and image coordinates
extern sSAPAMatrix3 SAPApixelToImageTransform(sSAPAImageSize imageSize, sSAPABitmapSize bitmapSize);
extern sSAPAMatrix3 SAPAimageToPixelTransform(sSAPAImageSize imageSize, sSAPABitmapSize bitmapSize);
extern sSAPAImageSize SAPAimageSizeFromBitmapSize(sSAPABitmapSize bitmapSize);
extern sSAPALineEquation SAPAtransformedLineEquation(sSAPALineEquation lineEquation, sSAPAMatrix3 transform);
extern sSAPAFrameCorners SAPAframeCornersFromEdgePolars(sSAPAFrameEdgePolars edgePolars);


extern sSAPALineEquation SAPAtransformedLineEquation(sSAPALineEquation lineEquation, sSAPAMatrix3 transform);
extern sSAPAFrameCorners SAPAframeCornersFromEdgePolars(sSAPAFrameEdgePolars edgePolars);
extern sSAPAFrameCorners SAPAframeCornersFromEdgeLines(sSAPAFrameEdgeLines edgeLines);


extern sSAPAPoint SAPAintersectionPointFromLineEquation(sSAPALineEquation line1, sSAPALineEquation line2);
extern sSAPALineEquation SAPAlineEquationFromPoints(sSAPAPoint point1, sSAPAPoint point2);
extern sSAPALineEquation SAPAlineEquationFromPolar(sSAPAPolar polar);
extern sSAPALineEquation SAPAlineEquationWithPositiveRho(sSAPALineEquation lineEquation);

extern float SAPAlineEquationDistanceToPoint(sSAPALineEquation lineEquation, sSAPAPoint point);
extern sSAPAPolar SAPAconstructPolarLine(sSAPABitmapSize objFuncSize, sSAPABitmapSize bitmapSize, int i, int j);

// frame corners
extern sSAPAFrameCorners SAPAFrameCornersMatchingImageRect(sSAPAImageSize imageSize);
extern sSAPASize SAPAestimatedAspectRatio(sSAPAFrameCorners corners);
extern bool SAPAisFrameCornersInImageRect(sSAPAFrameCorners corners, sSAPAImageSize imageSize);
extern float SAPAFrameCornersArea(sSAPAFrameCorners corners);
extern float SAPAFrameCornersAreaRatio(sSAPAFrameCorners corners, sSAPAImageSize imageSize);
extern sSAPABitmapSize SAPAgetLetterboxedBitmapSizeUsingAspectRatioAndLetterbox(sSAPASize aspectRatio, sSAPASize letterbox);
extern sSAPAFrameCorners SAPAedgeFrameCornersForEdgeIDusingFrame(int edgeID, sSAPAFrameCorners frameCorners);
extern sSAPAFrameCorners SAPAedgeFrameCornersForEdgeIDusingFrameAndConfig(int edgeID, sSAPAFrameCorners frameCorners, sSAPAFrameTrackingConfiguration config);
extern sSAPAFrameCorners SAPAcomputeMovedEdgeResult(sSAPAFrameCorners frameCorners, int edgePointID, sSAPAPoint translation);
extern sSAPAPoint SAPAPointMapWithHomography(sSAPAPoint p, sSAPAMatrix3 H);
extern sSAPAFrameCorners SAPAFrameCornersMapWithHomography(sSAPAFrameCorners frameCorners, sSAPAMatrix3 H);
extern int SAPAclosestCornerOrEdgeIdOfFrame(sSAPAFrameCorners frameCorners, sSAPAPoint point);
extern int SAPAclosestCornerIdOfFrame(sSAPAFrameCorners frameCorners, sSAPAPoint point);
extern SAPAFramePerspective SAPAFramePerspectiveFromFrameCorners(sSAPAFrameCorners frameCorners);

/*
 + (int)closestCornerOrEdgeIdOfFrame:(sAPAFrameCorners)frameCorners closestToPoint:(CGPoint)point;
 + (int)closestCornerIdOfFrame:(sAPAFrameCorners)frameCorners closestToPoint:(CGPoint)point;
 */
extern bool SAPAIsCornersVisible(sSAPAFrameCorners corners, int M, int N);
/*
 + (BOOL)isCornersInImageRect:(sAPAFrameCorners)corners imageSize:(sAPAImageSize)imageSize;
 + (BOOL)isValidFrameCoordinates:(sAPAFrameEdgePolars)frameCorners minDiff:(float)minDiff maxDiff:(float)maxDiff M:(int)M N:(int)N;
 
 + (sAPALineEquation)lineEquationFromPolar:(sAPAPolar)polar;
 + (sAPALineEquation)lineEquationWithPositiveRho:(sAPALineEquation)lineEquation;
 */


extern sSAPAMatrix3 SAPAprojectionMatrix();
extern sSAPAFrameCorners SAPAunitSquareCorners();
extern sSAPAFrameEdgePoints SAPAunitSquareEdgePoints();


extern sSAPAMatrix3 SAPAhomographyFromCorners(sSAPAFrameCorners fromCorners, sSAPAFrameCorners toCorners);
extern sSAPAMatrix3 SAPAhomographyToSquareCornersFromCorners(sSAPAFrameCorners fromCorners);
extern sSAPAMatrix3 SAPAhomographyFromSquareCornersToCorners(sSAPAFrameCorners toCorners);
extern sSAPAMatrix3 SAPAhomographyFromSquareCornersToCornersInvertible(sSAPAFrameCorners toCorners, bool inverse);

// for empirical testing, comparison
extern sSAPAFrameCorners SAPAFrameCornersShiftedToMatchTopRight(sSAPAFrameCorners corners);
extern sSAPAFrameCorners SAPAframeCornersShifted(sSAPAFrameCorners corners, int shiftIndex);
extern float SAPAframeCornersPerspectiveDistance(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB);
extern float SAPAframeCornersPerspectiveDistanceOptionallyCheckAllShifted(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB, bool checkAllShifted);
extern bool SAPAframeCornersAreAlmostEqualInPerspective(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB, bool checkAllShifted);
extern bool SAPAframeCornersAreAlmostEqualInPerspectiveWithThreshold(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB, float distanceThreshold);
extern bool SAPAframeCornersAreAlmostEqualWithThreshold(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB, float distanceThreshold);
extern bool SAPAframeCornersAreAlmostEqual(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB);
extern bool SAPAframeCornersAreAlmostEqualOptionallyCheckAllShifted(sSAPAFrameCorners frameA, sSAPAFrameCorners frameB, bool checkAllShifted);
  
  
  
#endif /* SAPACoordinateHelper_h */
  
#ifdef __cplusplus
}
#endif
