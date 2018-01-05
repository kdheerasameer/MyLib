//
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import <AVFoundation/AVFoundation.h>


@class APAScanVideoCamera, UIView;
@protocol APAScanVideoCameraImageBufferOutput;


typedef void(^APAScanStillImageCaptureCallback)(NSData * __nullable imageData, NSError * __nullable error);

typedef NS_ENUM(NSUInteger, APAScanCameraSampleBufferPixelFormat) {
  kLSCameraSampleBufferPixelFormat_32BGRA,                        // kCVPixelFormatType_32BGRA
  // For Future
//  kLSCameraSampleBufferPixelFormat_420YpCbCr8BiPlanarVideoRange,  // kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
//  kLSCameraSampleBufferPixelFormat_420YpCbCr8BiPlanarFullRange,   // kCVPixelFormatType_420YpCbCr8BiPlanarFullRange
};

/*!
 * Main delegate for video camera
 * All @em LSVideoCameraDelegate methods performed on main thread
 */
@protocol APAScanVideoCameraDelegate <NSObject>

@required

/*!
 * Camera has been initialized. You should not request or set camera properties before that moment
 * @param videoCamera sender
 */
- (void)videoCameraInitialized:(nonnull APAScanVideoCamera *)videoCamera;

/*!
 * Error happened
 * @param videoCamera sender
 * @param error error object, describing error that happened
 */
- (void)videoCamera:(nonnull APAScanVideoCamera *)videoCamera error:(nullable NSError *)error;

/*!
 * Notification of property (flash) change
 * @param videoCamera sender
 * @param newFlashMode new mode value
 */
- (void)videoCamera:(nonnull APAScanVideoCamera *)videoCamera changedFlashModeTo:(AVCaptureFlashMode)newFlashMode;

/*!
 * Notification of property (torch) change
 * @param videoCamera sender
 * @param newTorchMode new mode value
 */
- (void)videoCamera:(nonnull APAScanVideoCamera *)videoCamera changedTorchModeTo:(AVCaptureTorchMode)newTorchMode;

/*!
 * Called before capturing image
 * @param videoCamera sender
 */
- (void)videoCameraWillCapture:(nonnull APAScanVideoCamera *)videoCamera;

/*!
 * Called after capturing image. After capture image callback
 * @param videoCamera sender
 */
- (void)videoCameraDidCapture:(nonnull APAScanVideoCamera *)videoCamera;

@end


/*!
 * 'Tracker' delegate of the camera
 */
@protocol APAScanVideoCameraImageBufferOutput <NSObject>

@required

/*!
 * Called each frame, when sample buffer acquired from camera. If procession will take too long, next frames will be dropped
 * @param imageBuffer sample buffer itself
 */
- (void)processImageBuffer:(nullable CVImageBufferRef)imageBuffer;

@end


/*!
 * Wrapper around camera. Can handle simulator mode
 */
@interface APAScanVideoCamera : NSObject

/*!
* Proper contructor. Use this, to handle simulator mode
* @warning this method does not support subclasses
* @return <LSVideoCamera> or <LSSimulatorCamera> object
*/
+ (nullable instancetype)cameraWithDelegate:(nullable id<APAScanVideoCameraDelegate>)delegate
                    sampleBufferPixelFormat:(APAScanCameraSampleBufferPixelFormat)sampleBufferPixelFormat;

/*!
 * Frame tracker or similar object to process live camera buffer at real speed
 */
@property (nonatomic, strong, nullable) id<APAScanVideoCameraImageBufferOutput> videoDataOutputHandler;

/*!
 * Start flowing data from camera. This will restart camera preview
 */
- (void)startSession;

/*!
 * Stop flowing data from camera
 */
- (void)stopSession;

/*!
 * Size of video frame, displayed in preview video feed
 */
- (CGSize)videoDataOutputSize;
/*!
 * Orientation of video data related to portrait-oriented device
 */
- (UIImageOrientation)videoDataOutputOrientation;
/*!
 * Pixel format of sample buffer
 */
- (APAScanCameraSampleBufferPixelFormat)sampleBufferPixelFormat;

/*!
 * Capture still image. Orientation of device is ignored on simulator
 * @param callbackBlock main block. If no block - this will be an empty call
 * @param stopSession flag to whether stop camera session after image capture
 * @param pausePreviewView flag to whether pause camera preview after image capture
 * @param performAutoFocus flag to whether perform auto focus before image capture
 * @param drawFlashOnPreview flag to whether display flash effect on preview after image capture
 */
- (void)captureStillImageData:(nonnull APAScanStillImageCaptureCallback)callbackBlock
        stopSessionAfterwards:(BOOL)stopSession
             pausePreviewView:(BOOL)pausePreviewView
               afterAutoFocus:(BOOL)performAutoFocus
           drawFlashOnPreview:(BOOL)drawFlashOnPreview;

@end


@interface APAScanVideoCamera (Preview)

/*!
 * View, used to preview camera feed
 */
- (nullable UIView *)videoPreviewView;

- (void)pauseVideoPreview;
- (void)resumeVideoPreview;

@end


@interface APAScanVideoCamera (Properties)

/*!
 * Whether camera has flash
 */
- (BOOL)hasFlash;
/*!
 * Current mode of the flash. If [hasFlash] returns NO - this method will return AVCaptureFlashModeOff
 */
- (AVCaptureFlashMode)flashMode;
/*!
 * Change flash mode. If [hasFlash] returns NO - has no effect
 */
- (void)setFlashMode:(AVCaptureFlashMode)newValue;
/*!
 * Circles though available flash modes. If [hasFlash] returns NO - has no effect
 */
- (void)selectNextFlashMode;

/*!
 * Whether camera has torch
 */
- (BOOL)hasTorch;
/*!
 * Current mode of the torch. If [hasTorch] returns NO - this method will return AVCaptureTorchModeOff
 */
- (AVCaptureTorchMode)torchMode;
/*!
 * Change torch mode. If [hasTorch] returns NO - has no effect
 */
- (void)setTorchMode:(AVCaptureTorchMode)newValue;
/*!
 * Circles though available torch modes. If [hasTorch] returns NO - has no effect
 */
- (void)selectNextTorchMode;

/*!
 * Set autofocus mode to AVCaptureFocusModeAutoFocus
 * @param point point of interest. (0.5; 0.5) - is center of the camera frame
 */
- (void)autoFocusAtPoint:(CGPoint)point;
/*!
 * Set autofocus mode to AVCaptureFocusModeContinuousAutoFocus
 * @param point point of interest. (0.5; 0.5) - is center of the camera frame
 */
- (void)continuousAutoFocusAtPoint:(CGPoint)point;

- (void)setDesiredFrameRate:(int32_t)desiredFrameRate;
- (void)setAutoFocusRangeRestriction:(AVCaptureAutoFocusRangeRestriction)newValue;
- (void)setSmoothAutoFocusEnabled:(BOOL)newValue;
- (void)setWhiteBalanceMode:(AVCaptureWhiteBalanceMode)newValue;
- (void)setAutomaticallyEnablesLowLightBoostWhenAvailable:(BOOL)newValue;

@end

UIImageOrientation APAScanImageOrientationFromVideoRientation(AVCaptureVideoOrientation orientation);
