#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Convert image to grayscale
// Gray is what happens when all rgb values are the same on a given pixel
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create a ptr to access the components of RGBTRIPLE as an array
            BYTE* ptr = (BYTE*)&image[i][j];

            // Gather the values in each BYTE and sum them
            int rgbt_sum = 0;
            for (int k = 0; k < sizeof(RGBTRIPLE); k++)
            {
                rgbt_sum += ptr[k];
            }

            // Average those values and reassign the single value to each BYTE of that pixel
            uint8_t rgbt_avg = (rgbt_sum + 1)/ 3;

            for (int k = 0; k < sizeof(RGBTRIPLE); k++)
            {
                ptr[k] = rgbt_avg;
            }
        }
    }
}

// Convert image to sepia
// Sepia conversion formula:
// tb = 0.131B + 0.534G + 0.272R
// tg = 0.168B + 0.686G + 0.349R
// tr = 0.189B + 0.769G + 0.393R
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    uint8_t tr = 0;
    uint8_t tg = 0;
    uint8_t tb = 0;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create a ptr to access the components of RGBTRIPLE as an array
            BYTE* ptr = (BYTE*)&image[i][j];

            tb = (uint8_t) (0.131 * ptr[0]) + (0.534 * ptr[1]) + (0.272 * ptr[2]);
            tg = (uint8_t) (0.168 * ptr[0]) + (0.686 * ptr[1]) + (0.349 * ptr[2]);
            tr = (uint8_t) (0.189 * ptr[0]) + (0.769 * ptr[1]) + (0.393 * ptr[2]);

            ptr[0] = roundf(tb);
            ptr[1] = roundf(tg);
            ptr[2] = roundf(tr);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
