#ifndef INPUT_IMAGE_H
#define INPUT_IMAGE_H

#include <iostream>

#define HEIGHT_P 1920
#define WIDTH_P 1280

int grid_input[HEIGHT_P][WIDTH_P];

void read(FILE* input_image , int grid[HEIGHT_P][WIDTH_P]);

#endif