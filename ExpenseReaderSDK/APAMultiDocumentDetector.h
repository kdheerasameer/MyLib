//
//  APAMultiDocumentDetector.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 22.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "SAPATypes.h"
#import "APAMultiDocumentDetector.h"

typedef NS_ENUM(NSInteger, nAPAMDDResult) {
  /** multiple documents have been detected */
  nAPAMDDMultipleDocuments,
  /** a single document has been detected */
  nAPAMDDSingleDocument,
  /** no document has been detected */
  nAPAMDDNoDocument,
  /** detection not possible */
  nAPAMDDNotSupported
};

@interface APAMultiDocumentDetector : NSObject

// Multi Document Detection
- (BOOL)isSupported;
//- (nAPAMDDResult)detectMultipleDocuments:(UIImage *)image;
- (nAPAMDDResult)detectMultipleDocuments:(CVImageBufferRef)image;
- (nAPAMDDResult)detectMultipleDocuments:(sSAPAImageBuffer *)sourceBgra
                       sourceOrientation:(SAPAImageOrientation)sourceOrientation;

// Demo code
- (UIImage *)classifierSourceImage:(UIImage *)image;
- (UIImage *)classifierSourceImage:(sSAPAImageBuffer *)sourceBgra
                 sourceOrientation:(SAPAImageOrientation)sourceOrientation;

@end

