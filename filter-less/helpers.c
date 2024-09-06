#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Prototypes
uint8_t calculate_grayscale(RGBTRIPLE pixel);

// Convert image to grayscale
// Gray is what happens when all rgb values are the same on a given pixel
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create a ptr to access the components of RGBTRIPLE as an array
            // BYTE* ptr = (BYTE*)&image[i][j];

            uint8_t rgbt_avg = calculate_grayscale(image[i][j]);
            image[i][j].rgbtBlue = rgbt_avg;
            image[i][j].rgbtGreen = rgbt_avg;
            image[i][j].rgbtRed = rgbt_avg;
        }
    }
}

// Convert image to sepia
// sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
// sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
// sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE* ptr = (BYTE*)&image[i][j];

            // sb: sepia blue, sg: sepia green, sr: sepia red
            float sb = (0.131 * ptr[0]) + (0.534 * ptr[1]) + (0.272 * ptr[2]);
            float sg = (0.168 * ptr[0]) + (0.686 * ptr[1]) + (0.349 * ptr[2]);
            float sr = (0.189 * ptr[0]) + (0.769 * ptr[1]) + (0.393 * ptr[2]);

            // lb: leveled blue, lg: leveled green, lr: leveled red
            // You could probably do this with list comprehension
            // but no idea in C.
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
    BYTE *tmp_byte = (BYTE*)&image[height][width];
    for (int i = 0; i < height; i++)
    {
        // We need to stop half way through or we flip
        // the flipped pixels back
        for (int j = 0; j < width/2; j++)
        {
            // I don't understand why I can't reference tmp_byte.rgbtBlue
            // Understanding that I'm referencing each BYTE as if in an array
            // I wonder why I can't reference them by name rather than index
            tmp_byte[0] = image[i][j].rgbtBlue;
            tmp_byte[1] = image[i][j].rgbtGreen;
            tmp_byte[2] = image[i][j].rgbtRed;

            // We subtract one to avoid going out-of-bounds in the swap
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = tmp_byte[0];
            image[i][width - j - 1].rgbtGreen = tmp_byte[1];
            image[i][width - j - 1].rgbtRed = tmp_byte[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Let's make a copy of the image array, allows us to reset copy too.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // For each rgbtriple in the image array, let's average its bytes.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbt_sum_surrounding_blue = 0;
            int rgbt_sum_surrounding_green = 0;
            int rgbt_sum_surrounding_red = 0;
            float valid_pixel_counter = 0;

            // For any pixel within one square of the pixel
            // average its byte values
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {

                    int valid_i = (i + di >= 0 && i + di < height) ? i + di : -1;
                    int valid_j = (j + dj >= 0 && j + dj < width) ? j + dj : -1;
                    if (valid_i != -1 && valid_j != -1)
                    {
                        rgbt_sum_surrounding_blue  += copy[valid_i][valid_j].rgbtBlue;
                        rgbt_sum_surrounding_green += copy[valid_i][valid_j].rgbtGreen;
                        rgbt_sum_surrounding_red   += copy[valid_i][valid_j].rgbtRed;
                        valid_pixel_counter++;

                    }
                }
            }
            // Once we've got the average bytes, let's rebuild the image array with those values
            image[i][j].rgbtBlue = round((rgbt_sum_surrounding_blue) / valid_pixel_counter);
            image[i][j].rgbtGreen = round((rgbt_sum_surrounding_green)/ valid_pixel_counter);
            image[i][j].rgbtRed = round((rgbt_sum_surrounding_red)/ valid_pixel_counter);
        }
    }
}

// helper functions
uint8_t calculate_grayscale(RGBTRIPLE pixel)
{
    int rgbt_sum = pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed;
    // +1 to round properly
    return (rgbt_sum + 1) / 3;
}
