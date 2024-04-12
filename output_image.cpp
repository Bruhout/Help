#include <iostream> 
#include "output_image.hpp"

FILE *init_output(const char *filename)
{
    FILE *image = fopen(filename, "w");

    uint32_t image_size = 3 * HEIGHT_P_OUTPUT * WIDTH_P_OUTPUT;

    BITMAPFILEHEADER file_header = {
        0x4D42,
        sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + image_size,
        0, 0,
        sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)};

    BITMAPINFOHEADER info_header = {
        sizeof(BITMAPINFOHEADER),
        WIDTH_P_OUTPUT, HEIGHT_P_OUTPUT,
        1,
        24,
        0,
        image_size,
        0, 0,
        0, 0};

    fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, image);
    fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, image);
    // prepare the .bmp file for writing.
    return image;
}

void write(FILE* image , int grid_output[HEIGHT_P_OUTPUT][WIDTH_P_OUTPUT])
{
    for (int i=0 ; i<HEIGHT_P_OUTPUT ; i++)
    {
        for (int j=0 ; j<WIDTH_P_OUTPUT ; j++)
        {
            fwrite(&grid_output[i][j] , 3 , 1 , image);
        }
    }
}