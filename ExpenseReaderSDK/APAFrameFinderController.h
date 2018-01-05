//
//  APAFrameFinderController.h
//  Algorithm Prototypes
//
//  Created by Swagat PARIDA on 26/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APAScanVideoCamera.h"
#import "SAPATypes.h"
#import "APAMultiDocumentDetector.h"

typedef struct _sAPAFrameFinderResultData {
  sSAPAFrameCorners frame;
  BOOL frameIsTrusted;
  SAPAMoireDetectionResult moireDetectionResult;
  nAPAMDDResult mddResult;
} sAPAFrameFinderResultData;

//TODO: rename FrameFinder to PageRecognition
@class APAFrameFinderController;

@protocol APAFrameFinderControllerDelegate <NSObject>

@required
/*!
 * Main callback for <APAFrameFinderController>. Called on every [processImageBuffer:] call.
 * @param frameFinderResultData result data of frame finder.
 */
- (void)frameDetected:(sAPAFrameFinderResultData) frameFinderResultData;

@end

@interface APAFrameFinderController : NSObject <APAScanVideoCameraImageBufferOutput>
- (id _Nullable)initWithDelegate:(_Nullable id<APAFrameFinderControllerDelegate>) delegate;

/*!
 * Main delegate
 */
@property (nonatomic, weak, nullable) id<APAFrameFinderControllerDelegate> delegate;

/* Detect frame corners for UIImage with completion block
 * @param image UIImage on which frame corners to be detected
 * @param completionBlock block to be executed once frame corners are available
 */
- (void)detectFrameCornersForImage:(UIImage * _Nullable)image completion:(void (^ _Nullable)(sSAPAFrameCorners))completionBlock;

@end
