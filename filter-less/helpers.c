#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Prototypes

RGBTRIPLE calculate_sepia(RGBTRIPLE pixel);
RGBTRIPLE calculate_grayscale(RGBTRIPLE pixel);
void copy_image(int height, int width, RGBTRIPLE src[height][width], RGBTRIPLE dest[height][width]);

// Convert image to grayscale
// Gray is what happens when all rgb values are the same on a given pixel
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = calculate_grayscale(image[i][j]);
        }
    }
}

// Convert image to sepi
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = calculate_sepia(copy[i][j]);
        }

    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row_num = 0; row_num < height; row_num++)
    {
        // We need to stop half way through or we flip the flipped pixels back
        for (int left_index = 0; left_index < width/2; left_index++)
        {
            const int right_index = width - left_index - 1;

            const RGBTRIPLE tmp = image[row_num][left_index];
            image[row_num][left_index] = image[row_num][right_index];
            image[row_num][right_index] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);
    RGBTRIPLE temp_blur[height][width];

    // For each rgbtriple in the image array, let's average its bytes.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbt_sum_surrounding_blue = 0;
            int rgbt_sum_surrounding_green = 0;
            int rgbt_sum_surrounding_red = 0;
            float valid_pixel_counter = 0;

            // For any pixel within one square of the pixel average its byte values

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {

                    int valid_i = i + di;
                    int valid_j = j + dj;
                    if ((height > valid_i && valid_i >=0) && (width > valid_j && valid_j >= 0))
                    {
                        rgbt_sum_surrounding_blue  += copy[valid_i][valid_j].rgbtBlue;
                        rgbt_sum_surrounding_green += copy[valid_i][valid_j].rgbtGreen;
                        rgbt_sum_surrounding_red   += copy[valid_i][valid_j].rgbtRed;
                        valid_pixel_counter++;

                    }
                }
            }
            // Once we've got the average bytes, let's rebuild the image array with those values
            image[i][j].rgbtBlue = round(rgbt_sum_surrounding_blue / valid_pixel_counter);
            image[i][j].rgbtGreen = round(rgbt_sum_surrounding_green / valid_pixel_counter);
            image[i][j].rgbtRed = round(rgbt_sum_surrounding_red / valid_pixel_counter);
        }
    }
}

// helper functions
void copy_image(int height, int width, RGBTRIPLE src[height][width], RGBTRIPLE dest[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

RGBTRIPLE calculate_grayscale(RGBTRIPLE pixel)
{
    int rgbt_sum = pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed;
    // +1 to round properly
    int rgbt_avg = (rgbt_sum + 1) / 3;
    pixel.rgbtBlue = rgbt_avg;
    pixel.rgbtGreen = rgbt_avg;
    pixel.rgbtRed = rgbt_avg;

    return pixel;
}

// sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
// sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
// sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
RGBTRIPLE calculate_sepia(RGBTRIPLE pixel)
{
    float sb = (0.131 * pixel.rgbtBlue) + (0.534 * pixel.rgbtGreen) + (0.272 * pixel.rgbtRed);
    float sg = (0.168 * pixel.rgbtBlue) + (0.686 * pixel.rgbtGreen) + (0.349 * pixel.rgbtRed);
    float sr = (0.189 * pixel.rgbtBlue) + (0.769 * pixel.rgbtGreen) + (0.393 * pixel.rgbtRed);

    RGBTRIPLE sepia_pixel;
    sepia_pixel.rgbtBlue = (sb > 255) ? 255 : (sb < 0) ? 0 : round(sb);
    sepia_pixel.rgbtGreen = (sg > 255) ? 255 : (sg < 0) ? 0 : round(sg);
    sepia_pixel.rgbtRed = (sr > 255) ? 255 : (sr < 0) ? 0 : round(sr);

    return sepia_pixel;
}
