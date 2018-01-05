//
//  APAMetalContext.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 19.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>

#if !TARGET_OS_SIMULATOR
#import <Metal/Metal.h>
#import <CoreVideo/CoreVideo.h>
#endif

@interface APAMetalContext : NSObject
#if !TARGET_OS_SIMULATOR
+ (instancetype)defaultContext;

@property (nonatomic, strong) id<MTLDevice> device;
@property (nonatomic, strong) id<MTLLibrary> library;
@property (nonatomic, strong) id<MTLCommandQueue> commandQueue;
@property (assign, readonly) CVMetalTextureCacheRef textureCache;
#endif
@end

