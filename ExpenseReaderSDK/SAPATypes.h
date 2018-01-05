//
//  SAPATypes.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 05/09/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef SAPATypes_h
#define SAPATypes_h
  
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
  
  
  /*!
   * Holds edge image scores for each edge T, L, B, R
   *
   * Values range from 0 to 1 and can be interpreted as probability of a given edge image showing the edge of a document
   */
  typedef struct _sSAPAEdgeImageScores {
    union {
      struct {
        float T;
        float L;
        float B;
        float R;
      };
      float v[4];
    };
  } sSAPAEdgeImageScores;
  
  /*!
   * 3x3 matrix
   */
  typedef struct _sSAPAMatrix3 {
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
  } sSAPAMatrix3;
  
  
  /*!
   * 3 vector
   */
  typedef struct _sSAPAVector3 {
    float x;
    float y;
    float z;
  } sSAPAVector3;
  
  
  /*!
   * 2x2 matrix
   */
  typedef struct _sSAPAMatrix2 {
    float m11, m12;
    float m21, m22;
  } sSAPAMatrix2;
  
  /*!
   * 2 vector
   */
  typedef struct _sSAPAVector2 {
    float x;
    float y;
  } sSAPAVector2;
  
  
  /*!
   * Bitmap size in matrix notation.
   *
   * Pixels of the bitmap are identified with elements in a matrix.
   */
  typedef struct _sSAPABitmapSize {
    /** Row count (height) */
    int M;
    /** Column count (width) */
    int N;
  } sSAPABitmapSize;
  
  /*!
   * Defines the size of an image. Usually normalized and indepndent of associated bitmap resolution.
   *
   * Used for image coordinate system definition, in which it describes the width and height of a centered rectangle desribing the image boundary.
   */
  typedef struct _sSAPAImageSize {
    float w;
    float h;
  } sSAPAImageSize;
  
  /*!
   * Defines a general purpose size = (width, height)
   */
  typedef struct _sSAPASize {
    float width;
    float height;
  } sSAPASize;
  
  /*!
   * Point (x, y)
   */
  typedef struct _sSAPAPoint {
    float x;
    float y;
  } sSAPAPoint;
  
  /*!
   * Implicitly describes a line using a line equation.
   *
   * a*x + b*y + c = 0
   */
  typedef struct _sSAPALineEquation {
    float a;
    float b;
    float c;
  } sSAPALineEquation;
  
  /*!
   * Holds TR, TL, BL, BR corners of a frame
   */
  typedef struct _sSAPAFrameCorners {
    union {
      struct {
        /** Top right corner */
        sSAPAPoint TR;
        /** Top left corner */
        sSAPAPoint TL;
        /** Bottom left corner */
        sSAPAPoint BL;
        /** Bottom right corner */
        sSAPAPoint BR;
      };
      /** Array holding TR TL BL BR */
      sSAPAPoint c[4];
    };
    sSAPAImageSize imageSize;
  } sSAPAFrameCorners;
  
  /*!
   * Holds T, L, B, R edge line equations of a frame
   */
  typedef struct _sSAPAFrameEdgeLines {
    union {
      struct {
        /** Top edge */
        sSAPALineEquation T;
        /** Left edge */
        sSAPALineEquation L;
        /** Bottom edge */
        sSAPALineEquation B;
        /** Right edge */
        sSAPALineEquation R;
      };
      /** Array holding T L B R */
      sSAPALineEquation e[4];
    };
  } sSAPAFrameEdgeLines;
  
  /*!
   * Holds T, L, B, R center points of an edge
   */
  typedef struct _sSAPAFrameEdgePoints {
    union {
      struct {
        /** Top edge point */
        sSAPAPoint T;
        /** Left edge point */
        sSAPAPoint L;
        /** Bottom edge point */
        sSAPAPoint B;
        /** Right edge point */
        sSAPAPoint R;
      };
      /** Array holding T L B R */
      sSAPAPoint p[4];
    };
  } sSAPAFrameEdgePoints;
  
  /*!
   * Holds polar coordinates (phi, rho)
   */
  typedef struct _sSAPAPolar {
    /** angle measured against x axis */
    float phi;
    /** (signed) distance from origin */
    float rho;
  } sSAPAPolar;
  
  /*!
   * Holds T, L, B, R polar coordinates (phi, rho) defining the line equations
   *
   * cos(phi)*x + sin(phi)*y = rho
   */
  typedef struct _sSAPAFrameEdgePolars {
    union {
      struct {
        /** Top edge */
        sSAPAPolar T;
        /** Left edge */
        sSAPAPolar L;
        /** Bottom edge */
        sSAPAPolar B;
        /** Right edge */
        sSAPAPolar R;
      };
      /** Array holding T L B R */
      sSAPAPolar p[4];
    };
  } sSAPAFrameEdgePolars;
  
  /*!
   * Holds all configuration parameters for frame tracking
   */
  typedef struct _sSAPAFrameTrackingConfiguration {
    /** bitmap size used to hold each edge image */
    sSAPABitmapSize edgeImageBitmapSize;
    /** relative factor / multiplier defining the edge width */
    float edgeWidthFactor;
    /** absolute edge height */
    float edgeHeight;
    /** threshold for seperating inliers and outliers */
    float ransacInlierDistance;
    /** edge point max percentage factor */
    float edgePointMaxFactor;
  } sSAPAFrameTrackingConfiguration;
  
  /*!
   * Contains labels for all frame perspectives
   */
  typedef enum _SAPAFramePerspective {
    /** No frame */
    SAPAFramePerspectiveNoFrame = 0,
    /** Frame is fairly rectangular - Good */
    SAPAFramePerspectiveGood,
    /** Angle between document normal and camera axis is too big */
    SAPAFramePerspectiveBadPerspective,
    /** Angle of rotation around Z axis is too big */
    SAPAFramePerspectiveBadRotation,
    /** Size of frame in proportion to image size is too big */
    SAPAFramePerspectiveTooBig,
    /** Size of frame in proportion to image size is too small */
    SAPAFramePerspectiveTooSmall,
  } SAPAFramePerspective;
  
  /*!
   * Contains labels for all color transforms
   */
  typedef enum _SAPAColorTransform {
    SAPAColorTransformBGRA, // used in iOS
    SAPAColorTransformRGBA, // used in Android
    SAPAColorTransformRed,
    SAPAColorTransformGreen,
    SAPAColorTransformBlue,
    SAPAColorTransformY, // Luma
    SAPAColorTransformU,
    SAPAColorTransformV,
    SAPAColorTransformHue,
    SAPAColorTransformSaturation,
    SAPAColorTransformChroma,
    SAPAColorTransformChromaScoreRed,
    SAPAColorTransformChromaScoreYellow,
    SAPAColorTransformChromaScoreGreen,
    SAPAColorTransformChromaScoreCyan,
    SAPAColorTransformChromaScoreBlue,
    SAPAColorTransformChromaScoreMagenta,
    SAPAColorTransformCount
  } SAPAColorTransform;
  
  /*!
   * Basic type - image data (usually in floats [0; 1])
   */
  typedef struct sSAPAImageBuffer {
    void *data;
    size_t height;
    size_t width;
    size_t rowBytes; // 1D array
  } sSAPAImageBuffer;
  
  /*!
   * Contains buffers to be shared among functions of SAPAColorTransformHelper
   */
  typedef struct _sSAPAColorTransformConverter {
    sSAPAImageBuffer tempBuffer;
    sSAPAImageBuffer *localBuffers;
    bool *isCached;
    sSAPABitmapSize bitmapSize;
    int Ntotal;
  } sSAPAColorTransformConverter;
  
  /**
   * Describes the image image orientation relative to its raw buffer
   *
   * Example: `SAPAImageOrientationRight` means 90 deg CW rotation. That means, the image is rotated 90° CW relative to its raw buffer. Equivalently, the raw buffer is rotated 90° CCW relative to the image
   */
  typedef enum _SAPAImageOrientation {
    /** default orientation */
    SAPAImageOrientationUp,
    /** 180° rotation */
    SAPAImageOrientationDown,
    /** 90° CCW rotation */
    SAPAImageOrientationLeft,
    /** 90° CW rotation */
    SAPAImageOrientationRight,
    /** as above but image mirrored along other axis. horizontal flip */
    SAPAImageOrientationUpMirrored,
    /** horizontal flip */
    SAPAImageOrientationDownMirrored,
    /** vertical flip */
    SAPAImageOrientationLeftMirrored,
    /** vertical flip */
    SAPAImageOrientationRightMirrored,
  } SAPAImageOrientation;
  
  /*!
   * Representation for array of float complex numbers
   */
  typedef struct _sAPADSPSplitComplex {
    float *realp;
    float *imagp;
  } SAPADSPSplitComplex;
  
  /**
   * Holds T, L, B, R center points of an edge
   */
  typedef struct _sSAPARansacLineParams {
    /** Linear model parameters */
    sSAPALineEquation bestLineEquation;
    /** Indices of inliers */
    sSAPAImageBuffer inlierMarker;
    /** Total number of inliers */
    int inlierCount;
  } sSAPARansacLineParams;
  
  /*!
   * Holds all configuration parameters for frame detection
   */
  typedef struct _sSAPAFrameDetectionConfiguration {
    /** Source Bitmap Size to use to create cached kernels */
    sSAPABitmapSize fdSourceBitmapSize;
    /**  determines number of edge detection kernels */
    sSAPABitmapSize objFuncSize;
    /** X-directional radius of kernel */
    float sigmaX;
    /** Y-directional radius of kernel */
    float sigmaY;
    /** threshold for numbers to be treated as non-zero */
    float nonZeroTreshold;
    /** threshold to identify best lines */
    float maximumAcceptableThreshold;
    /** control how close local maxima can be */
    int nonMaxSuppressionRadius;
    /** max number of lines to extracted from objective function */
    int maxCount;
    /** min permissible angle between two adjacent edges of a valid frame */
    float minDiff;
    /** max permissible angle between two adjacent edges of a valid frame */
    float maxDiff;
    /** source letter box size */
    int sourceLetterBoxSizeForTracking;
    /** total number of kernel columns */
    int maxCountBestLines;
    /*Valid number of color transforms*/
    int iValidColorTransformCount;
    /*Color Transforms Array*/
    SAPAColorTransform *colorTransformsArray;
  } sSAPAFrameDetectionConfiguration;
  
  /*!
   * Holds all global parameters of frame detection manager
   */
  typedef struct _sSAPAFDManagerParams {
#warning TODO: rename params
    /** stores all customized parameters of FD algorithm */
    sSAPAFrameDetectionConfiguration params;
    /** stores all old parameters of FD algorithm */
    sSAPAFrameDetectionConfiguration paramsUsedToCreateKernels;
    /** stores all customized parameters of FT algorithm */
    sSAPAFrameTrackingConfiguration ftConfig;
    /** computes color transforms for FD source images (small) */
    sSAPAColorTransformConverter fdSourceCTConverter;
    /** computes color transforms for edge images */
    sSAPAColorTransformConverter edgeCTConverter;
    /** cache buffers to store sparse positions of all edge detection kernels for a given set of algorithm parameters */
    sSAPAImageBuffer* sparseKernelPosition; //
    /** cache buffers to store values of sparse positions of all edge detection kernels for a given set of algorithm parameters */
    sSAPAImageBuffer* sparseKernelValue;
  } sSAPAFDManagerParams;
  
  /*!
   * Holds info of each ML training sample
   */
  typedef struct _sSAPAFeatureVector {
    /** stores a pointer to feature vector */
    float* featureData;
    /** classification result */
    int classLabel;
  } sSAPAFeatureVector;
  
  
  
  /*!
   * Contains different methods for estimating Standard Deviation score for Moire pattern detection
   */
  typedef enum _SAPAMoireScoreEstimationType {
    SAPAMoireMinimumStandardDeviationScore,
    SAPAMoireAverageStandardDeviationScore,
    SAPAMoireWeightedGrayStandardDeviationScore
  } SAPAMoireScoreEstimationType;
  
  /*!
   * Contains the possible results for Moire Pattern
   */
  typedef enum _SAPAMoireDetectionResult {
    SAPAMoireScreenCapture,
    SAPAMoireNormalCapture,
    SAPAMoireNotSupported
  } SAPAMoireDetectionResult;
  
  
  /*!
   * Contains parameters to be used for detecting Moire Patterns
   */
  typedef struct _sSAPAMoireParams {
    float highFreqThresh;
    int stdWindowSize;
    bool isColor;
    int level;
    bool useShared;
    float detectedFreq;
  } sSAPAMoireParams;
  
#endif /* SAPATypes_h */
  
#ifdef __cplusplus
}
#endif

