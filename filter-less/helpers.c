#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray_value = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Gather rgb values and average them
            int rgbt_sum = 0;

            rgbt_sum += image[i][j].rgbtRed;
            rgbt_sum += image[i][j].rgbtGreen;
            rgbt_sum += image[i][j].rgbtBlue;

            uint8_t rgbt_avg = (rgbt_sum + 1)/ 3;

            image[i][j].rgbtRed = rgbt_avg;
            image[i][j].rgbtGreen = rgbt_avg;
            image[i][j].rgbtBlue = rgbt_avg;
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
