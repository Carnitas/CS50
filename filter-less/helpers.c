#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Convert image to grayscale
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
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
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
