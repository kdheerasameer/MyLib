//
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class APAScanPage;


typedef void(^APAExpenseReaderAPICallback)(NSString * __nullable response, NSError * __nullable error);


// https://console.expensereader.amadeus.com/
@interface APAExpenseReaderAPIClient : NSObject

/// Do not initialize this object directly - obtain it through [[LSScan sharedInstance] xtractorAPIClient]
- (nonnull instancetype)initWithAPiKey:(nonnull NSString *)apiKey;

/// Set url, host and accepted version to be used for uploading to semantics API.
- (void)setApiBaseURL:(nonnull NSString*)baseURL apiHost:(nonnull NSString*)host apiAcceptedVersion:(nonnull NSString*)acceptedVersion;

/// Upload source image of the given page to semantics API.
- (void)uploadPage:(nullable APAScanPage *)page completion:(void (^ _Nullable)(NSString * _Nullable, NSError * _Nullable))completionBlock;

/// Upload image to semantics API. If you already have image saved as a page - it is MUCH better to use [- uploadPage...] method
- (void)uploadImage:(nullable UIImage *)image forceFrameDetection:(BOOL)forceFrameDetection completion:(void (^ _Nullable)(NSString * _Nullable, NSError * _Nullable))completionBlock;

@end
