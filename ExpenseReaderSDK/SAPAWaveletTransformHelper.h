//
//  SAPAWaveletDecompositionHelper.h
//  Algorithm Prototypes
//
//  Created by Eldho ABRAHAM on 25/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#ifndef SAPAWaveletTransformHelper_h
#define SAPAWaveletTransformHelper_h

#include <stdio.h>
#include <stdlib.h>
#include "SAPATypes.h"

extern void SAPAHaarFWT2D(sSAPAImageBuffer* inputImg, int iterations, bool isColor);
extern void SAPAHaarIWT2D(sSAPAImageBuffer* inputImg, int iterations, bool isColor);

#endif /* SAPAWaveletDecompositionHelper_h */

