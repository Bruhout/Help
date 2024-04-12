#include <iostream>
#include "output_image.hpp"


void read(FILE* input_image , int grid_input[HEIGHT_P][WIDTH_P])
{
    fseek(input_image , 14 , SEEK_SET);
    
    for (int i =0 ; i<HEIGHT_P ; i++)
    {
        for (int j=0 ; i<WIDTH_P ; j++)
        {
            fread(&grid_input[i][j] , 3 , 1 , input_image);
        }
    }
}