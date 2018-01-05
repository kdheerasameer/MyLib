//
//  APAImageCache.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 16.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface APAImageCache : NSObject

+ (instancetype)sharedCache;

// cache management
- (void)clearCache;
- (void)deleteAllFilesStartingWithKey:(NSString *)key;
- (void)createExportDocumentCache:(NSData *) jsonExportData;
- (void)clearExportDocumentCache;
- (void)importDocumentCache:(void (^)(NSData* jsonExportData,
                                      BOOL success,
                                      NSString* error))completion;
- (UIImage *)loadSourceImageUsingKeyFromDocumentCache:(NSString *)key;

// image loading and saving
- (BOOL)fileIsCachedUsingKey:(NSString *)key;
- (void)saveJpegImage:(UIImage *)image
   compressionQuality:(float)compressionQuality
             usingKey:(NSString *)key;
- (void)save1BitTIFFImage:(UIImage *)image
                 usingKey:(NSString *)key;
- (UIImage *)loadImageUsingKey:(NSString *)key;
- (long long)fileSizeUsingKey:(NSString *)key;

- (void)saveDictionary:(NSDictionary *)dict usingKey:(NSString *)key;
- (NSDictionary *)loadDictionaryUsingKey:(NSString *)key;
- (BOOL)saveSourceImageIntoDocumentCacheFromImageCachePath:(NSString *)sourcePath
                                           destinationPath:(NSString *)destinationPath;
- (void)moveSourcePageIntoImageCache;


@end

