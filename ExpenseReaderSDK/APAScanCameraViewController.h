//
//  APAScanCameraViewController.h
//  Algorithm Prototypes
//
//  Created by Swagat PARIDA on 25/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APAScanVideoCamera.h"
#import "APAFrameFinderController.h"
#import "APAFrameTrackerView.h"
#import "APAFrameStateView.h"
#import "APAScanCameraTimerButton.h"


@interface APAScanCameraViewController : UIViewController <APAScanVideoCameraDelegate, APAFrameFinderControllerDelegate>

/*!
 * Container view for camera preview and frameTrackerView
 * This will be used in [viewDidLoad]. Set this earlier or in xib
 */

@property (weak, nonatomic, nullable) IBOutlet UIView *cameraPreviewView;

/*!
 * Animatable camera button
 * This will be used in [viewDidLoad]. Set this earlier or in xib.
 */
@property (nonatomic, strong, nullable, readonly) IBOutlet APAScanCameraTimerButton *cameraTimerButton;

/*!
 * Setter method for block to be executed after photo is captured
 * This block will be called after the corresponding page is added to the document
 */
- (void)setPhotoCaptureCompletionBlock:(void(^_Nullable)())photoCaptureCompletionBlock;

/*!
 * Setter method for "good" and "bad" frame colors
 */
- (void)setFrameColorForGoodFrame:(UIColor*_Nullable)goodFrameColor badFrameColor:(UIColor*_Nullable)badFrameColor;

/*!
 * Setter method for color of feedback message on frame perspective
 */
- (void)setGoodFramePerspectiveMessageColor:(UIColor*_Nullable)goodFramePerspectiveMessageColor badFramePerspectiveMessageColor:(UIColor*_Nullable)badFramePerspectiveMessageColor;

/*!
 * Setter method for active and inactive cameraTimerButton state
 */
- (void)setButtonActiveStateColor:(UIColor*_Nullable)activeStateColor inactiveStateColor:(UIColor*_Nullable)inactiveStateColor;

/*!
 * Enable/disable autoshot feature
 */
- (void)enableAutoshot:(BOOL)enable;

/*!
 * Enable/disable display of frame tracking
 */
- (void)enableFrameTracking:(BOOL)enable;

/*!
 * Enable/disable screen capture detection feature
 */
- (void)enableScreenCaptureDetection:(BOOL)enable;

/*!
 * Enable/disable multiple document detection feature
 */
- (void)enableMultiDocumentDetection:(BOOL)enable;

/*!
 * Set camera configurations
 * @param stopSessionAfterCapture flag to whether stop camera session after photo capture
 * @param pausePreviewAfterCapture flag to whether pause camera video preview after photo capture
 * @param autoFocusBeforeCapture flag to whether auto focus before photo capture
 * @param showFlashEffectOnCapture flag to whether show flash effect on display after photo capture
 */
- (void)setStopSessionAfterCapture:(BOOL)stopSessionAfterCapture
          pausePreviewAfterCapture:(BOOL)pausePreviewAfterCapture
            autoFocusBeforeCapture:(BOOL)autoFocusBeforeCapture
          showFlashEffectOnCapture:(BOOL)showFlashEffectOnCapture;

/*
 * Change and select next flash mode
 */
- (void)selectNextFlashMode;

/*
 * Implement the below callback method to get update when video camera is initialized
 * - (void)videoCameraInitialized:(APAScanVideoCamera *)videoCamera
 */

/*
 * Implement the below callback method to get update when flash mode is changed
 * - (void)videoCamera:(APAScanVideoCamera *)videoCamera changedFlashModeTo:(AVCaptureFlashMode)newFlashMode
 */


@end
