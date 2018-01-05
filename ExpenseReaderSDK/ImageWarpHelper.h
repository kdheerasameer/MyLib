//
//  ImageWarpHelper.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 17/05/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APACoordinateHelper.h"
#include "SAPAImageBufferHelper.h"
#include "SAPAImageWarpHelper.h"

@interface ImageWarpHelper : NSObject

+ (UIImage *)createWarpedImage:(UIImage *)sourceImage
                  frameCorners:(sSAPAFrameCorners)frameCorners
                     letterbox:(sSAPASize)letterbox;
+ (UIImage *)createWarpedImage:(UIImage *)sourceImage
                  frameCorners:(sSAPAFrameCorners)frameCorners
              warpedBitmapSize:(sSAPABitmapSize)warpedBitmapSize;
+ (void)createWarpedImageBuffer:(sSAPAImageBuffer *)warpedBgraBuffer
                   sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   frameCorners:(sSAPAFrameCorners)frameCorners
                      letterbox:(sSAPASize)letterbox;
+ (void)createWarpedImageBuffer:(sSAPAImageBuffer *)warpedBgraBuffer
                   sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   frameCorners:(sSAPAFrameCorners)frameCorners
               warpedBitmapSize:(sSAPABitmapSize)warpedBitmapSize;
+ (void)createWarpedImageBuffer:(sSAPAImageBuffer *)warpedBgraBuffer
                   sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   frameCorners:(sSAPAFrameCorners)frameCorners
               warpedBitmapSize:(sSAPABitmapSize)warpedBitmapSize
                      useShared:(BOOL)useShared;
+ (void)createWarpedImageBuffer:(sSAPAImageBuffer *)warpedBgraBuffer
                   sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
              sourceOrientation:(SAPAImageOrientation)sourceOrientation
                   frameCorners:(sSAPAFrameCorners)frameCorners
               warpedBitmapSize:(sSAPABitmapSize)warpedBitmapSize;
+ (void)createWarpedImageBuffer:(sSAPAImageBuffer *)warpedBgraBuffer
                   sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
              sourceOrientation:(SAPAImageOrientation)sourceOrientation
                   frameCorners:(sSAPAFrameCorners)frameCorners
               warpedBitmapSize:(sSAPABitmapSize)warpedBitmapSize
                      useShared:(BOOL)useShared;


// image buffer (BGRA) resize
+ (void)createResizedImageBuffer:(sSAPAImageBuffer *)resizedBgraBuffer
                    sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   newBitmapSize:(sSAPABitmapSize)newBitmapSize
                       useShared:(BOOL)useShared;
+ (void)createResizedImageBuffer:(sSAPAImageBuffer *)resizedBgraBuffer
                    sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
               sourceOrientation:(SAPAImageOrientation)sourceOrientation
                   newBitmapSize:(sSAPABitmapSize)newBitmapSize
                       useShared:(BOOL)useShared;
+ (void)createResizedImageBuffer:(sSAPAImageBuffer *)resizedBgraBuffer
                    sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   newBitmapSize:(sSAPABitmapSize)newBitmapSize
                  doAntiAliasing:(BOOL)doAntiAliasing
                       useShared:(BOOL)useShared;
+ (void)createResizedImageBuffer:(sSAPAImageBuffer *)resizedBgraBuffer
                    sourceBuffer:(sSAPAImageBuffer *)sourceBgraBuffer
                   newBitmapSize:(sSAPABitmapSize)newBitmapSize
               sourceOrientation:(SAPAImageOrientation)sourceOrientation
                  doAntiAliasing:(BOOL)doAntiAliasing
                       useShared:(BOOL)useShared;

@end

