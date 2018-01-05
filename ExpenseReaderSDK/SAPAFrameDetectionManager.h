//
//  SAPAFrameDetectionManager.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 07/09/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAFrameDetectionManager_h
#define SAPAFrameDetectionManager_h

#include <stdio.h>
#include "SAPATypes.h"
#include <stdbool.h>

extern sSAPAFDManagerParams SAPAFDManagerNew(bool useShared);

extern void SAPAFDManagerDealloc(sSAPAFDManagerParams *fdManagerParams);

extern sSAPAFrameDetectionConfiguration SAPADefaultFDConfiguration();

extern bool SAPAConfigIsEqualToConfigWRTKernelCreation(sSAPAFrameDetectionConfiguration config1,
                                                       sSAPAFrameDetectionConfiguration config2);

#endif /* SAPAFrameDetectionManager_h */

#ifdef __cplusplus
}
#endif