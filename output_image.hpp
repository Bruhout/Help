#ifndef OUTPUT_IMAGE_H
#define OUTPUT_IMAGE_H

#include <iostream>
#include "input_image.hpp"

#define PIXELS_PER_BLOCK 1
#define WIDTH_P_OUTPUT (int)(WIDTH_P / PIXELS_PER_BLOCK)
#define HEIGHT_P_OUTPUT (int)(HEIGHT_P / PIXELS_PER_BLOCK)

typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    int32_t bfOffBits;
} __attribute__((packed)) BITMAPFILEHEADER;

typedef struct
{
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} __attribute__((packed)) BITMAPINFOHEADER;

FILE* init_output(const char* filename);
void write(FILE* image , int grid_output[HEIGHT_P_OUTPUT][WIDTH_P_OUTPUT]);

#endif
