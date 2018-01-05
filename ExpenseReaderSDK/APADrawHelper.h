//
//  APADrawHelper.h
//  Algorithm Prototypes
//
//  Created by ashna bhatia on 26/06/2017.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "APACoordinateHelper.h"

@interface APADrawHelper : UIViewController

+ (void)drawFrame:(sSAPAFrameCorners)frameCorners layer:(CAShapeLayer *)layer imageView:(UIView *)imageView;
+ (void)drawMultipleFrames:(sSAPAFrameCorners *)frameCorners count:(int)count layer:(CAShapeLayer *)layer imageView:(UIView *)imageView;
+ (UIBezierPath *)pathForMultipleFrames:(sSAPAFrameCorners *)frameCorners count:(int)count viewSize:(CGSize)viewSize;
+ (UIBezierPath *)pathForMultipleFramesAspectFill:(sSAPAFrameCorners *)frameCorners count:(int)count viewSize:(CGSize)viewSize;
+ (void)drawMultipleLines:(sSAPALineEquation *)lines count:(int)count imageSize:(sSAPAImageSize)imageSize layer:(CAShapeLayer *)layer view:(UIView *)view;
+ (UIBezierPath*)drawLinePath:(sSAPALineEquation)line layer:(CAShapeLayer *)layer imageSize:(sSAPAImageSize)imageSize imageView:(UIView *)imageView;

@end
