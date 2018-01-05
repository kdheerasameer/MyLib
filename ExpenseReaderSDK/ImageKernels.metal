//
//  ImageKernels.metal
//  Algorithm Prototypes
//
//  Created by Martin Stämmler on 19.10.17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//
#if !TARGET_OS_SIMULATOR
#include <metal_stdlib>
using namespace metal;

struct APAMetalWarpFilterUniforms {
  float3x3 HdstPixelToSrcPixel;
};

struct APAMetalBinarizationMapFilterUniforms {
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalGrayLMCNewMapFilterUniforms {
  float bgR;
  float bgG;
  float bgB;
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalRGBLMCNewMapFilterUniforms {
  float bgR;
  float bgG;
  float bgB;
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalGrayLMCMapFilterUniforms {
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalRGBLMCMapFilterUniforms {
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalHaarWaveletHorizontalFilterUniforms {
  int halfWidth;
};

struct APAMetalHaarWaveletVerticalFilterUniforms {
  int halfHeight;
};

struct APAMetalResizeFilterUniforms {
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalRgbaToYuvaResizeFilterUniforms {
  float ax;
  float bx;
  float ay;
  float by;
};

struct APAMetalLmcIbgFilterUniforms {
  uint maxU;
  uint maxV;
  uint kernelSize;
  uint kernelOverlap;
};

struct APAMetalLmcCbCrFilterUniforms {
  float pixelThreshold;
};

/**
 * Simple resize
 * @param inTexture input texture, assuming RGBA format or similar, is sampled
 * @param outTexture output texture
 */
kernel void simple_resize(texture2d<half, access::sample> inTexture [[texture(0)]],
                          texture2d<half, access::write> outTexture [[texture(1)]],
                          constant APAMetalResizeFilterUniforms &uniforms [[buffer(0)]],
                          uint2 gid [[thread_position_in_grid]]) {
  float2 sourcePosition = float2(gid.x*uniforms.ax + uniforms.bx, gid.y*uniforms.ay + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 sourceColor = inTexture.sample(s, sourcePosition);
  outTexture.write(sourceColor, gid);
}

/**
 * RGBA to YUVA resize
 * @param inTexture input texture, assuming RGBA format or similar, is sampled
 * @param outTexture output texture (YUVA)
 */
kernel void rgba_to_yuva_resize(texture2d<half, access::sample> inTexture [[texture(0)]],
                                texture2d<half, access::write> outTexture [[texture(1)]],
                                constant APAMetalResizeFilterUniforms &uniforms [[buffer(0)]],
                                uint2 gid [[thread_position_in_grid]]) {
  float2 sourcePosition = float2(gid.x*uniforms.ax + uniforms.bx, gid.y*uniforms.ay + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 sourceColor = inTexture.sample(s, sourcePosition);
  
  half y = dot(sourceColor.rgb, half3(0.299, 0.587, 0.114));
  half u = (sourceColor.b - y)*0.493 + 0.5; // u = (b - y)*0.493 + 0.5
  half v = (sourceColor.r - y)*0.877 + 0.5; // v = (r - y)*0.877 + 0.5
  half4 outColor = half4(y, u, v, 1);
  outTexture.write(outColor, gid);
}

/**
 * YUVA to RGBA
 */
kernel void yuva_to_rgba(texture2d<float, access::read> inTexture [[texture(0)]],
                         texture2d<float, access::write> outTexture [[texture(1)]],
                         uint2 gid [[thread_position_in_grid]]) {
  float4 inColor = inTexture.read(gid); // yuva all in range 0..1
  float y = inColor.r; // y
  float b = y + (inColor.g - 0.5)/0.493; // b = y + (u - 0.5)/0.493
  float r = y + (inColor.b - 0.5)/0.877; // r = y + (v - 0.5)/0.877
  float g = dot(float3(y, r, b), float3(1.0/0.587, -0.299/0.587, -0.114/0.587)); // g = (y - 0.299*r - 0.114*b)/0.587
  float4 outColor = float4(r, g, b, 1); // rgba, range not checked
  outTexture.write(outColor, gid);
}

/**
 * estimated background color defined as mode in kernel region
 */
kernel void lmc_ibg(texture2d<half, access::read> inTexture [[texture(0)]],
                    texture2d<half, access::write> outTexture [[texture(1)]],
                    constant APAMetalLmcIbgFilterUniforms &uniforms [[buffer(0)]],
                    uint2 gid [[thread_position_in_grid]]) {
  int u0s = gid.x*uniforms.kernelSize - uniforms.kernelOverlap;
  uint u0 = u0s >= 0 ? u0s : 0;
  uint u1 = min((gid.x + 1)*uniforms.kernelSize - 1 + uniforms.kernelOverlap, uniforms.maxU);
  int v0s = gid.y*uniforms.kernelSize - uniforms.kernelOverlap;
  uint v0 = v0s >= 0 ? v0s : 0;
  uint v1 = min((gid.y + 1)*uniforms.kernelSize - 1 + uniforms.kernelOverlap, uniforms.maxV);
  
  uint rHist[256];
  uint gHist[256];
  uint bHist[256];
  for (int i = 0; i < 256; i++) {
    rHist[i] = 0;
    gHist[i] = 0;
    bHist[i] = 0;
  }
  uint maxR = 0;
  uint maxRcount = 0;
  uint maxG = 0;
  uint maxGcount = 0;
  uint maxB = 0;
  uint maxBcount = 0;
  for (uint u = u0; u <= u1; u++) {
    for (uint v = v0; v <= v1; v++) {
      uint2 position(u, v);
      half4 color = 255*inTexture.read(position);
      uint colorR = uint(color.r);
      uint colorG = uint(color.g);
      uint colorB = uint(color.b);
      rHist[colorR]++;
      gHist[colorG]++;
      bHist[colorB]++;
      if (rHist[colorR] > maxRcount) {
        maxRcount = rHist[colorR];
        maxR = colorR;
      }
      if (gHist[colorG] > maxGcount) {
        maxGcount = gHist[colorG];
        maxG = colorG;
      }
      if (bHist[colorB] > maxBcount) {
        maxBcount = bHist[colorB];
        maxB = colorB;
      }
    }
  }
  
  half4 outColor = half4(float(maxR)/255.0, float(maxG)/255.0, float(maxB)/255.0, 1.0);
  outTexture.write(outColor, gid);
}

/**
 * horizontal and vertical connectivity map
 */
kernel void lmc_cbcr(texture2d<half, access::read> inTexture [[texture(0)]],
                     texture2d<half, access::write> outTexture [[texture(1)]],
                     constant APAMetalLmcCbCrFilterUniforms &uniforms [[buffer(0)]],
                     uint2 gid [[thread_position_in_grid]]) {
  uint2 posBottom = uint2(gid.x, gid.y + 1);
  uint2 posRight = uint2(gid.x + 1, gid.y);
  
  half4 inColor = inTexture.read(gid);
  half4 inColorB = inTexture.read(posBottom);
  half4 inColorR = inTexture.read(posRight);
  
  half3 dB = abs(inColor.rgb - inColorB.rgb);
  half3 dR = abs(inColor.rgb - inColorR.rgb);
  
  // r-channel shouldn't be written like below
  half4 outColor = half4(dR.r,
                         round(fmax(dR.r, fmax(dR.g, dR.b))*255) <= round(255*2*uniforms.pixelThreshold),
                         round(fmax(dB.r, fmax(dB.g, dB.b))*255) <= round(255*2*uniforms.pixelThreshold),
                         1);
  outTexture.write(outColor, gid);
}

/**
 * Gray LMC (new)
 * @param inTexture RGBA source image
 * @param inTexture2 RGBA background map, usually of smaller size than source image
 * @param outTexture RGBA filtered image, same size as source image
 * @param uniforms contains estimated background color and coordinate transform for resampling of the background map to match the size of source image and filtered image
 */
kernel void gray_lmc_map_new(texture2d<float, access::read> inTexture [[texture(0)]],
                             texture2d<float, access::sample> inTexture2 [[texture(1)]],
                             texture2d<float, access::write> outTexture [[texture(2)]],
                             constant APAMetalGrayLMCNewMapFilterUniforms &uniforms [[buffer(0)]],
                             uint2 gid [[thread_position_in_grid]]) {
  float2 uv = float2(uniforms.ax*gid.x + uniforms.bx, uniforms.ay*gid.y + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  float4 inColor2 = inTexture2.sample(s, uv);
  
  float4 inColor = inTexture.read(gid); // image color
  float4 outColor = float4(inColor.r <= inColor2.r ? (uniforms.bgR*inColor.r)/inColor2.r : 1 - ((1 - uniforms.bgR)*(1 - inColor.r))/(1 - inColor2.r),
                           inColor.g <= inColor2.g ? (uniforms.bgG*inColor.g)/inColor2.g : 1 - ((1 - uniforms.bgG)*(1 - inColor.g))/(1 - inColor2.g),
                           inColor.b <= inColor2.b ? (uniforms.bgB*inColor.b)/inColor2.b : 1 - ((1 - uniforms.bgB)*(1 - inColor.b))/(1 - inColor2.b),
                           1);
  float y = dot(outColor.rgb, float3(0.299, 0.587, 0.114)); // y = 0.299*r + 0.587*g + 0.114*b
  outTexture.write(float4(float3(y), 1.0), gid);
}


/**
 * RGB LMC (new)
 * @param inTexture RGBA source image
 * @param inTexture2 RGBA background map, usually of smaller size than source image
 * @param outTexture RGBA filtered image, same size as source image
 * @param uniforms contains estimated background color and coordinate transform for resampling of the background map to match the size of source image and filtered image
 */
kernel void rgb_lmc_map_new(texture2d<float, access::read> inTexture [[texture(0)]],
                            texture2d<float, access::sample> inTexture2 [[texture(1)]],
                            texture2d<float, access::write> outTexture [[texture(2)]],
                            constant APAMetalRGBLMCNewMapFilterUniforms &uniforms [[buffer(0)]],
                            uint2 gid [[thread_position_in_grid]]) {
  float2 uv = float2(uniforms.ax*gid.x + uniforms.bx, uniforms.ay*gid.y + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  float4 inColor2 = inTexture2.sample(s, uv);
  
  float4 inColor = inTexture.read(gid); // image color
  float4 outColor = float4(inColor.r <= inColor2.r ? (uniforms.bgR*inColor.r)/inColor2.r : 1 - ((1 - uniforms.bgR)*(1 - inColor.r))/(1 - inColor2.r),
                           inColor.g <= inColor2.g ? (uniforms.bgG*inColor.g)/inColor2.g : 1 - ((1 - uniforms.bgG)*(1 - inColor.g))/(1 - inColor2.g),
                           inColor.b <= inColor2.b ? (uniforms.bgB*inColor.b)/inColor2.b : 1 - ((1 - uniforms.bgB)*(1 - inColor.b))/(1 - inColor2.b),
                           1);
  outTexture.write(outColor, gid);
}

/**
 * Homography warp
 * @param inTexture input texture, assuming RGBA format or similar, is sampled
 * @param outTexture output texture
 * @param uniforms holds the homography matrix used for warping
 */
kernel void homography_warp(texture2d<half, access::sample> inTexture [[texture(0)]],
                            texture2d<half, access::write> outTexture [[texture(1)]],
                            constant APAMetalWarpFilterUniforms &uniforms [[buffer(0)]],
                            uint2 gid [[thread_position_in_grid]]) {
  float3 outPosition = float3(float2(gid), 1.0); // destination (x, y, 1) position
  float3 inPosition = uniforms.HdstPixelToSrcPixel*outPosition; // source (u, v, w) position
  // bilinear interpolation
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 outColor = inTexture.sample(s, inPosition.xy/inPosition.z); // source (u/w, v/w) position (cartesian)
  outTexture.write(outColor, gid);
}

/**
 * Binarization map filter
 * @param inTexture1 source image
 * @param inTexture2 binarization threshold map
 * @param outTexture binarized image (same size as source image)
 * @param uniforms holds the rescale info used for sampling the lower resolution threshold map
 */
kernel void binarization_map(texture2d<half, access::read> inTexture1 [[texture(0)]],
                             texture2d<half, access::sample> inTexture2 [[texture(1)]],
                             texture2d<half, access::write> outTexture [[texture(2)]],
                             constant APAMetalGrayLMCMapFilterUniforms &uniforms [[buffer(0)]],
                             uint2 gid [[thread_position_in_grid]]) {
  half4 imageColor = inTexture1.read(gid);
  half imageGray = dot(imageColor.rgb, half3(0.299, 0.587, 0.114));
  float2 mapPosition = float2(gid.x*uniforms.ax + uniforms.bx, gid.y*uniforms.ay + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 mapColor = inTexture2.sample(s, mapPosition);
  outTexture.write(half4(half3(imageGray > mapColor.r), 1.0), gid);
}

/**
 * Gray LMC map filter
 * @param inTexture1 source image
 * @param inTexture2 light map (mean-free, "0.5" is zero)
 * @param outTexture filtered image (same size as source image)
 * @param uniforms holds the rescale info used for sampling the lower resolution light map
 */
kernel void gray_lmc_map(texture2d<half, access::read> inTexture1 [[texture(0)]],
                         texture2d<half, access::sample> inTexture2 [[texture(1)]],
                         texture2d<half, access::write> outTexture [[texture(2)]],
                         constant APAMetalGrayLMCMapFilterUniforms &uniforms [[buffer(0)]],
                         uint2 gid [[thread_position_in_grid]]) {
  half4 imageColor = inTexture1.read(gid);
  half imageGray = dot(imageColor.rgb, half3(0.299, 0.587, 0.114));
  float2 mapPosition = float2(gid.x*uniforms.ax + uniforms.bx, gid.y*uniforms.ay + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 mapColor = inTexture2.sample(s, mapPosition);
  outTexture.write(half4(half3(imageGray - (mapColor.r - 0.5)), 1.0), gid);
}

/**
 * RGB LMC map filter
 * @param inTexture1 source image
 * @param inTexture2 light map (mean-free, "0.5" is zero)
 * @param outTexture filtered image (same size as source image)
 * @param uniforms holds the rescale info used for sampling the lower resolution light map
 */
kernel void rgb_lmc_map(texture2d<half, access::read> inTexture1 [[texture(0)]],
                        texture2d<half, access::sample> inTexture2 [[texture(1)]],
                        texture2d<half, access::write> outTexture [[texture(2)]],
                        constant APAMetalRGBLMCMapFilterUniforms &uniforms [[buffer(0)]],
                        uint2 gid [[thread_position_in_grid]]) {
  half4 imageColor = inTexture1.read(gid);
  float2 mapPosition = float2(gid.x*uniforms.ax + uniforms.bx, gid.y*uniforms.ay + uniforms.by);
  constexpr sampler s(coord::pixel, address::clamp_to_edge, filter::linear);
  half4 mapColor = inTexture2.sample(s, mapPosition);
  outTexture.write(half4(imageColor.rgb - half3(mapColor.r - 0.5), 1.0), gid);
}

/**
 * HAAR Wavelet filter horizontal
 * @param inTexture1 source image
 * @param outTexture filtered image (same size as source image)
 * @param uniforms holds the input image info
 */
kernel void haar_wavelet_horizontal(texture2d<float, access::read> inTexture1 [[texture(0)]],
                                    texture2d<float, access::write> outTexture [[texture(1)]],
                                    constant APAMetalHaarWaveletHorizontalFilterUniforms &uniforms [[buffer(0)]],
                                    uint2 gid [[thread_position_in_grid]]) {
  if (gid.x < uint(uniforms.halfWidth)) {
    //first half of the row
    uint2 pos1 = uint2(2*gid.x + 0, gid.y);
    uint2 pos2 = uint2(2*gid.x + 1, gid.y);
    float4 imageColor1 = inTexture1.read(pos1);
    float4 imageColor2 = inTexture1.read(pos2);
    float4 outputColor = float4((imageColor1.rgb + imageColor2.rgb)*0.5, 1.0);
    outTexture.write(outputColor, gid);
  } else {
    //second half of the row
    uint2 pos1 = uint2(2*(gid.x - uniforms.halfWidth) + 0, gid.y);
    uint2 pos2 = uint2(2*(gid.x - uniforms.halfWidth) + 1, gid.y);
    float4 imageColor1 = inTexture1.read(pos1);
    float4 imageColor2 = inTexture1.read(pos2);
    float4 outputColor = float4((imageColor1.rgb - imageColor2.rgb)*0.5 + float3(0.5), 1.0);
    outTexture.write(outputColor, gid);
  }
}

/**
 * HAAR Wavelet filter vertical
 * @param inTexture1 source image
 * @param outTexture filtered image (same size as source image)
 * @param uniforms holds the input image info
 */
kernel void haar_wavelet_vertical(texture2d<float, access::read> inTexture1 [[texture(0)]],
                                  texture2d<float, access::write> outTexture [[texture(1)]],
                                  constant APAMetalHaarWaveletVerticalFilterUniforms &uniforms [[buffer(0)]],
                                  uint2 gid [[thread_position_in_grid]]) {
  if (gid.y < uint(uniforms.halfHeight)) {
    //first half of the row
    uint2 pos1 = uint2(gid.x, 2*gid.y + 0);
    uint2 pos2 = uint2(gid.x, 2*gid.y + 1);
    float4 imageColor1 = inTexture1.read(pos1);
    float4 imageColor2 = inTexture1.read(pos2);
    float4 outputColor = float4((imageColor1.rgb + imageColor2.rgb)*0.5, 1.0);
    outTexture.write(outputColor, gid);
  } else {
    //second half of the row
    uint2 pos1 = uint2(gid.x, 2*(gid.y - uniforms.halfHeight) + 0);
    uint2 pos2 = uint2(gid.x, 2*(gid.y - uniforms.halfHeight) + 1);
    float4 imageColor1 = inTexture1.read(pos1);
    float4 imageColor2 = inTexture1.read(pos2);
    float4 outputColor = float4((imageColor1.rgb - imageColor2.rgb)*0.5 + float3(0.5), 1.0);
    outTexture.write(outputColor, gid);
  }
}
#endif

