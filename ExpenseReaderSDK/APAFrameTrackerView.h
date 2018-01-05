//
//  APAFrameTrackerView.h
//  Algorithm Prototypes
//
//  Created by Dheerasameer KOTTAPALLI on 30/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SAPATypes.h"

@interface APAFrameTrackerView : UIView

/*
 * Change current frame and state
 */
- (void)animateToFrame:(sSAPAFrameCorners)frame good:(BOOL)goodFrame animated:(BOOL)animated;


/*!
 * Duration of all animations (change frame, change state)
 * Default value is 0.3 second.
 */
@property (nonatomic, assign) CFTimeInterval generalAnimationDuration;

/*!
 * Width of lines for frame
 * Default value is 3.0
 */
@property (nonatomic, assign) CGFloat frameLineWidth;

/*!
 * Color for frame rectangle, when frame is @em Nil
 * Default value is light gray
 */
@property (nonatomic, strong) UIColor *colorNoFrame;

/*!
 * Color for frame, when it is "bad"
 * Default value is red
 */
@property (nonatomic, strong) UIColor *colorBadFrame;

/*!
 * Color for frame, when it is "good"
 * Default value is green
 */
@property (nonatomic, strong) UIColor *colorGoodFrame;

/*!
 * Color for fill for area outside of frame
 * default value is black with alpha of 0.3
 */
@property (nonatomic, strong) UIColor *colorOuterFill;

@end
