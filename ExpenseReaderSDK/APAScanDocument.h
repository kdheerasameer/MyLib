//
//  APAScanDocument.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 24.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APAScanPage.h"

@interface APAScanDocument : NSObject

@property (strong, nonatomic) NSMutableArray<APAScanPage *> *pages;
@property (assign, readwrite) int currentPageIndex;

/**
 * Add a new page with UIImage and frame corners
 * @param sourceImage UIImage for page
 * @param frameCorners frame corners for the page image
 */
- (void)addPageWithImage:(UIImage *)sourceImage frameCorners:(sSAPAFrameCorners)frameCorners;

/*! @brief serialize the entire document and all pages into json data and strore in document cache
 * @param completion : callback block after execution of serialization
 */
- (void)exportDocumentWithCompletion:(void (^)(BOOL success))completion;

/*!@brief read entire serialized document and deserialized into pages. Also read source images from document cache
 * @param completion : callback block after execution of reading from document cache
 */
- (void)importDocumentWithCompletion:(void (^)(BOOL success))completion;

/*!@brief export all the pages in current APAScanDocument as PDF document
 * @param completion : callback block which returns the pdf file path and a boolean if it's a success or failure
 */
- (void)exportToPDF:(void (^)(NSString* pdfPath, BOOL success))completion;

- (void)addTestDocument;
- (void)addTestPage;
- (void)addTestPage2;
@end

