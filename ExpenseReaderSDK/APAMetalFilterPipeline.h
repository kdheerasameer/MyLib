//
//  APAFilterPipeline.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 17.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APAScanPage.h"
#import "APAScanPageConstants.h"


@interface APAMetalFilterPipeline : NSObject

+ (instancetype)sharedFilterPipeline;

- (void)saveSourceImage:(UIImage *)sourceImage
                   page:(APAScanPage *)page;

- (UIImage*)getSourceImage:(APAScanPage *)page;

- (void)createSourceImage:(APAScanPage *)page
                letterbox:(sSAPABitmapSize)letterbox
               completion:(void (^)(UIImage *image, BOOL success))completion;

- (void)createPreviewImage:(APAScanPage *)page
                    filter:(nAPAImageFilter)filter
                 letterbox:(sSAPABitmapSize)letterbox
                completion:(void (^)(UIImage *image, BOOL success))completion;
- (void)createOutputImageFile:(APAScanPage *)page
                       filter:(nAPAImageFilter)filter
                    letterbox:(sSAPABitmapSize)letterbox
                   completion:(void (^)(BOOL success, NSString *resultKey))completion;
- (void)moveSourcePageIntoDocumentCache:(APAScanPage *)sourcePage
                        destinationPath:(NSString *)destinationPath;
- (void)moveSourcePageIntoImageCache;

@end

