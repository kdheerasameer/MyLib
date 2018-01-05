//
//  APAScanDocumentManager.h
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 24.11.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APAScanDocument.h"

@interface APAScanDocumentManager : NSObject

@property (strong, nonatomic) APAScanDocument *document;

+ (instancetype)sharedManager;

@end
