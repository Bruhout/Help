#include <iostream>
#include "input_image.hpp"
#include "output_image.hpp"


int main(void)
{
    int grid_input[HEIGHT_P][WIDTH_P];
    int grid_output[HEIGHT_P_OUTPUT][WIDTH_P_OUTPUT] = {0x000000};


    FILE* input_image=fopen("image.bmp" , "r");
    read(input_image , grid_input);

    FILE* output_image=init_output("output.bmp");

    for (int i = 0 ; i<HEIGHT_P_OUTPUT ; i++)
    {
        for (int j=0 ; j<WIDTH_P_OUTPUT ; j++)
        {
            grid_output[i][j] = grid_input[i][j];
        }
    }

    write(output_image , grid_output);

    fclose(input_image);
    fclose(output_image);
}
























// typedef struct Block
// {
//     int color;
//     uint16_t pixel_count_x;
//     uint16_t pixel_count_y;
//     uint16_t position_x;
//     uint16_t position_y;


//     void DrawBlock()
//     {
//         //Bounds checking
//         if (pixel_count_x + position_x > WIDTH_P || pixel_count_y + position_y > HEIGHT_P)
//         {
//             std::cout << "Invalid indexes passed, Drawing terminated" << '\n';
//             return;
//         }

//         for (int i = position_y ; i<position_y + pixel_count_y ; i++)
//         {
//             for (int j = position_x ; j<position_x + pixel_count_x ; j++)
//             {
//                 grid[i][j] = color;
//             }
//         }
//     }
// } Block;