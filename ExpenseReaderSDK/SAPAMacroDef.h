//
//  SAPAMacroDef.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 29/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAMacroDef_h
#define SAPAMacroDef_h

#warning TODO: why no ifndef check???
#define MAX(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

#define MIN(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a < _b ? _a : _b; })

#endif /* SAPAMacroDef_h */

#ifdef __cplusplus
}
#endif