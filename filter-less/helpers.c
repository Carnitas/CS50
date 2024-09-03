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
// sb = 0.131B + 0.534G + 0.272R
// sg = 0.168B + 0.686G + 0.349R
// tr = 0.189B + 0.769G + 0.393R

// sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
// sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
// sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue



void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create a ptr to access the components of RGBTRIPLE as an array
            // There's a way to do all of this with less repeated code
            // Let's come back to it.
            BYTE* ptr = (BYTE*)&image[i][j];

            // sb: sepia blue, sg: sepia green, sr: sepia red
            float sb = (0.131 * ptr[0]) + (0.534 * ptr[1]) + (0.272 * ptr[2]);
            float sg = (0.168 * ptr[0]) + (0.686 * ptr[1]) + (0.349 * ptr[2]);
            float sr = (0.189 * ptr[0]) + (0.769 * ptr[1]) + (0.393 * ptr[2]);

            // lb: leveled blue, lg: leveled green, lr: leveled red
            BYTE lb = (sb > 255) ? 255 : (sb < 0) ? 0 : round(sb);
            BYTE lg = (sg > 255) ? 255 : (sg < 0) ? 0 : round(sg);
            BYTE lr = (sr > 255) ? 255 : (sr < 0) ? 0 : round(sr);

            ptr[0] = lb;
            ptr[1] = lg;
            ptr[2] = lr;
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
