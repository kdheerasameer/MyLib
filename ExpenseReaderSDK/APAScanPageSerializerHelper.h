//
//  APAScanPageSerializerHelper.h
//  Algorithm Prototypes
//
//  Created by Swagat PARIDA on 05/12/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#include "SAPATypes.h"
#include "APAScanPage.h"

#ifndef APAScanPageSerializerHelper_h
#define APAScanPageSerializerHelper_h


@interface APAScanPageSerializerHelper : NSObject

+ (NSDictionary *)getJsonDictFromFrameCorners:(sSAPAFrameCorners)corners;
+ (APAScanPage *)deserializePageDictionary:(NSDictionary*)pageDictionary pageUUID:(NSString*)pageUUID;

@end
#endif /* APAScanPageSerializerHelper_h */

