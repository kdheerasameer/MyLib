//
//  SAPAvDSPLib.h
//  Algorithm Prototypes
//
//  Created by Suresh YERVA on 21/08/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SAPAvDSPLib_h
#define SAPAvDSPLib_h

#include <stdio.h>
#include "SAPAImageBufferHelper.h"
#include "SAPATypes.h"

void vDSP_vfltu8_shared(const uint8_t* A, const int strideA, float* B, const int strideB, const int count);
void vDSP_vsmul_shared(const float* A, const int strideA, const float* scale, float* B, const int strideB, const int count);
void vDSP_vsmsma_shared(const float* A, const int strideA, const float* B, const float* C, const int strideC, const float* D, float* E, const int strideE, const int count);
void vDSP_vsma_shared(const float* A, const int strideA, const float* B, const float* C, const int strideC, float* D, const int strideD, const int count);
void vDSP_vsbsm_shared(const float* A, const int strideA, const float* B, const int strideB, const float* C, float* D, const int strideD, const int count);
void vDSP_vmul_shared(const float* A, const int strideA, const float* B, const int strideB, float* C, const int strideC, const int count);
void vDSP_vmin_shared(const float* A, const int strideA, const float* B, const int strideB, float* C, const int strideC, const int count);
void vDSP_vsmsa_shared(const float* A, const int strideA, const float* B, const float* C, float* D, const int strideD, const int count);
void vDSP_vabs_shared(const float* A, const int strideA, float* C, const int strideC, const int count);
void vDSP_vsadd_shared(const float* A, const int strideA, const float* B, float *C, const int strideC, const int count);
void vDSP_vdist_shared(const float* A, const int strideA, const float* B, const int strideB, float* C, const int strideC, const int count);
void vDSP_zvphas_shared(SAPADSPSplitComplex* A, const int strideA, float* C, const int strideC, const int count);
void vDSP_vindex_shared(const float *A, const float *B, const int strideB, float *C, const int strideC, const int count);
void vDSP_dotpr_shared(const float *A, const int strideA, const float *B, const int strideB, float *C, const int count);
void vDSP_minv_shared(const float *A, const int strideA, float *C, const int count);
void vDSP_maxv_shared(const float *A, const int strideA, float *C, const int count);
void vDSP_vfill_shared(const float *A, float *C, const int strideC, const int count);
void vDSP_vlim_shared(const float *A, const int strideA, const float *B, const float *C, float *D, const int strideD, const unsigned int count);
void vDSP_sve_shared(const float *A, const int strideA, float *C, const unsigned int count);
void vDSP_meanv_shared(const float *A, const int strideA, float *C, const unsigned int count);
void vDSP_normalize_shared(const float *A, const int strideA, float *C, const int strideC, float *mean, float *stddev,const unsigned int count);
  
#endif /* SAPAvDSPLib_h */

#ifdef __cplusplus
}
#endif
