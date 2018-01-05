//
//  ExpenseReaderSDK.h
//  ExpenseReaderSDK
//
//  Created by Dheerasameer KOTTAPALLI on 05/12/17.
//  Copyright © 2017 Amadeus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APAScanDocumentManager.h"
#import "SAPACoordinateHelper.h"
#import "APAScanCameraViewController.h"
#import "APAScanDocumentManager.h"
#import "APADrawHelper.h"
#import "APAFrameDetectionManager.h"
#import "APAFrameTrackingHelper.h"
#import "SAPAFrameDetectionManager.h"
#include "SAPAImageBufferHelper.h"
#import "APAExpenseReaderAPIClient.h"

@interface ExpenseReaderSDK : NSObject

+ (instancetype)sharedInstance;

@end

@interface ExpenseReaderSDK (InitialSetup)
// You must call methods in this section before other calls to SDK - usually in [application:didFinishLaunchingWithOptions:]

/// Set license key.
/// You MUST call this method only once.
- (void)setupLicenseKey:(nonnull NSString *)licenseKey;

@end

@interface ExpenseReaderSDK (ExpenseReaderAPI)

/// Client for Expense Reader API
/// https://console.expensereader.amadeus.com/
- (nullable APAExpenseReaderAPIClient *)expenseReaderAPIClient;

- (void)setExpenseReaderApiKey:(nonnull NSString *)apiKey;

- (void)setExpenseReaderApiBaseURL:(nonnull NSString*)baseURL apiHost:(nonnull NSString*)host apiAcceptedVersion:(nonnull NSString*)acceptedVersion;

@end
