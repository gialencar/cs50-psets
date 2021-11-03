#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // clone a pixel from the image
            RGBTRIPLE pixel = image[row][col];
            float sum = pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed;
            // calculate the average of the three color channels
            int average = round(sum / 3);

            // set each of the colors in the pixel to the averaged value
            image[row][col].rgbtBlue = average;
            image[row][col].rgbtGreen = average;
            image[row][col].rgbtRed = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // get original RGB values of the pixel
            int originalRed = image[row][col].rgbtRed;
            int originalGreen = image[row][col].rgbtGreen;
            int originalBlue = image[row][col].rgbtBlue;

            // calculate sepia values
            float sepiaRGB[3];
            sepiaRGB[0] = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaRGB[1] = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaRGB[2] = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // values should be capped at 255
            for (int i = 0; i < 3; i++)
            {
                if (sepiaRGB[i] > 255)
                {
                    sepiaRGB[i] = 255;
                }
            }

            // assign sepia values to the pixel
            image[row][col].rgbtRed = (int)sepiaRGB[0];
            image[row][col].rgbtGreen = (int)sepiaRGB[1];
            image[row][col].rgbtBlue = (int)sepiaRGB[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        // create a temporary row of pixels
        RGBTRIPLE temp_row[width];

        for (int col = 0; col < width; col++)
        {
            temp_row[width - 1 - col] = image[row][col];
        }

        for (int col = 0; col < width; col++)
        {
            image[row][col] = temp_row[col];
        }

        // for (int col = 0; col < width; col++)
        // {
        //     // swap original with inverted row
        //     image[row][col] = temp_row[col];
        // }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur_img[height][width];



    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col ++)
        {
            // calculate average
            int avgR = 0;
            int avgG = 0;
            int avgB = 0;
            float pix_count = 0;

            // upper 3
            for (int i = row - 1, k = col - 1; k <= col + 1; k++)
            {
                if (i >= 0 && k >= 0 && i < height && k < width)
                {
                    avgR += image[i][k].rgbtRed;
                    avgG += image[i][k].rgbtGreen;
                    avgB += image[i][k].rgbtBlue;

                    pix_count += 1;
                }

            }

            //middle 3
            for (int i = row, k = col - 1; k <= col + 1; k++)
            {
                if (i >= 0 && k >= 0 && i < height && k < width)
                {
                    avgR += image[i][k].rgbtRed;
                    avgG += image[i][k].rgbtGreen;
                    avgB += image[i][k].rgbtBlue;
                    pix_count += 1;
                }
            }

            // lower 3
            for (int i = row + 1, k = col - 1; k <= col + 1; k++)
            {
                if (i >= 0 && k >= 0 && i < height && k < width)
                {
                    avgR += image[i][k].rgbtRed;
                    avgG += image[i][k].rgbtGreen;
                    avgB += image[i][k].rgbtBlue;
                    pix_count += 1;
                }
            }


            // averages
            avgR = round(avgR / pix_count);
            avgG = round(avgG / pix_count);
            avgB = round(avgB / pix_count);

            blur_img[row][col].rgbtRed = avgR;
            blur_img[row][col].rgbtGreen = avgG;
            blur_img[row][col].rgbtBlue = avgB;

        }
    }

    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col ++)
        {
            image[row][col] = blur_img[row][col];
        }
    }

    return;
}
