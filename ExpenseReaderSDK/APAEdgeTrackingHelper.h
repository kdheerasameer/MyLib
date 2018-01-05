//
//  APAEdgeTrackingHelper.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 05/07/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImageBufferHelper.h"
#import "APACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"

@interface APAEdgeTrackingHelper : NSObject
// Filters
+ (float)edgeImageScoreOfEdgeImage:(sSAPAImageBuffer *)edgeImage useVDSP:(BOOL)useVDSP;
+ (void)findShortestPath:(sSAPAImageBuffer *)graph
          filteredBuffer:(sSAPAImageBuffer *)filteredBuffer
              bitmapSize:(sSAPABitmapSize)bitmapSize
                  Ntotal:(int)Ntotal
    optionalOutputBuffer:(sSAPAImageBuffer *)outputBuffer
                outputID:(int)outputID
         pointListBuffer:(sSAPAImageBuffer *)pointListBuffer
             pointListID:(int)pointListID
              edgePoints:(float *)edgePoints
          edgePointCount:(int *)totalPointCount
                 useVDSP:(BOOL)useVDSP;
+ (void)applyHorizontalEdgeFilter:(sSAPAImageBuffer *)filteredBuffer
                      sourceImage:(sSAPAImageBuffer *)edgeImageBuffer
                          useVDSP:(BOOL)useVDSP;
+ (void)edgePointClassification:(sSAPAImageBuffer *)filteredBuffer
                     tempBuffer:(sSAPAImageBuffer *)tempBuffer
                        useVDSP:(BOOL)useVDSP
             edgePointMaxFactor:(float)edgePointMaxFactor;

+ (sSAPALineEquation)fitLineToEdgeImage:(sSAPAImageBuffer *)edgeImageBuffer
                   ransacInlierDistance:(float)ransacInlierDistance
                     edgePointMaxFactor:(float)edgePointMaxFactor;
+ (sSAPALineEquation)fitLineToEdgeImage:(sSAPAImageBuffer *)edgeImageBuffer
                   optionalOutputBuffer:(sSAPAImageBuffer *)outputBuffer
                               outputID:(int)outputID;
+ (sSAPALineEquation)fitLineToEdgeImage:(sSAPAImageBuffer *)edgeImageBuffer
                   optionalOutputBuffer:(sSAPAImageBuffer *)outputBuffer
                               outputID:(int)outputID
                        pointListBuffer:(sSAPAImageBuffer *)pointListBuffer
                            pointListID:(int)pointListID
                                useVDSP:(BOOL)useVDSP
                   ransacInlierDistance:(float)ransacInlierDistance
                     edgePointMaxFactor:(float)edgePointMaxFactor;
@end
