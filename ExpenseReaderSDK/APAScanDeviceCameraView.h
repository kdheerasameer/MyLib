

#import <UIKit/UIKit.h>

@class AVCaptureSession;

/// Camera video feed is rendered here
@interface APAScanDeviceCameraView : UIView

- (void)setCaptureSession:(AVCaptureSession *)newSession;
- (void)resetSession:(AVCaptureSession *)newSession;
- (void)pauseVideoPreview;
- (void)resumeVideoPreview;

/// Display "flash" animation on top of a video
- (void)animateFlash;

@end
