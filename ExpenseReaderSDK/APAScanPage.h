//
//  APAScanPage.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 17.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "SAPATypes.h"
#include "APAScanPageConstants.h"

@interface APAScanPage : NSObject

@property (assign, readwrite) sSAPAFrameCorners frameCorners;
@property (assign, readwrite) NSString* filterName;
@property (assign, readwrite) nAPAPageRotation pageRotation;
@property (assign, readwrite) nAPAImageFilter imageFilter;

/// OCR extracted JSON data.
@property (copy, nullable) NSString *ocrJson;

/// Size of image after OCR preprocessing
@property (nonatomic, readwrite) CGSize apiInputImageSize;

- (instancetype)initWithFrameCorners:(sSAPAFrameCorners)frameCorners;
- (NSString *)imageKey;
- (NSString *)imageAndFrameKey;
- (sSAPAFrameCorners)frameCornersWithPageRotation;
- (void)setUUID:(NSString*)uuid;
- (void)setFilter:(NSString*)filterName;
- (NSInteger)getFilter;

/**
 * Asynchronously creates a preview image of the source image (photo) used for this page. Image size is set so the image will fit perfectly in an image view with content mode UIViewContentModeScaleAspectFit
 * @param viewSize the bounds size of an image view
 * @param completion after generating the image, the image is provided using this completion block
 */
- (void)sourcePreviewImageWithViewSize:(CGSize)viewSize
                            completion:(void (^)(UIImage *image, BOOL success))completion;

/**
 * Asynchronously creates a preview image of a cropped page with given filter. Image size is set so the image will fit perfectly in an image view with content mode UIViewContentModeScaleAspectFit
 * @param filter defines which filter to use
 * @param viewSize the bounds size of an image view
 * @param completion after generating the image, the image is provided using this completion block
 */
- (void)previewImageWithFilter:(nAPAImageFilter)filter
                      viewSize:(CGSize)viewSize
                    completion:(void (^)(UIImage *image, BOOL success))completion;

/**
 * Asynchronously creates the output image of a page with given filter.
 *
 * NOTE: Completion block is not called on the main thread
 * @param filter defines which filter to use
 * @param completion after generating the image, the image is provided using this completion block (no main thread)
 */
- (void)outputImageWithFilter:(nAPAImageFilter)filter
                   completion:(void (^)(UIImage *image, BOOL success))completion;

/**
 * Synchronously creates the output image of a page with given filter.
 * @param filter defines which filter to use
 */
- (UIImage *)outputImageWithFilter:(nAPAImageFilter)filter;

//document serializer apis
- (NSDictionary *)pageDictionary:(NSString*)newPageKey;

// create PDF for current page
- (void)exportPageToPDF:(void (^)(NSString *pdfPath, BOOL success))completion;

@end



