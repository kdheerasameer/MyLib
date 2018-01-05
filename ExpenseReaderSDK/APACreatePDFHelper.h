//
//  APACreatePDFHelper.h
//  ExpenseReaderSDK
//
//  Created by Suresh YERVA on 27/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APAScanDocument.h"

@interface APACreatePDFHelper : NSObject

+ (void)exportDocToPDF:(APAScanDocument *)document
            completion:(void (^)(NSString *pdfPath, BOOL success))completion;
+ (void)exportToPDF:(NSMutableArray<UIImage*>*)images completion:(void (^)(NSString *pdfPath, BOOL success))completion;

@end
