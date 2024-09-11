#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {

//     // Open the memory card

//     // While there's still data left to read from the memory card

//     // Create JPEGs from the data
// }

// Figre out how to print out sequential names in a for-loop, probably outside the while loop
// Figure out file i/o stuff to write all bytes to a file until the next jpeg signature.

// Variables
typedef uint8_t BYTE;

// Prototypes
bool possible_image_start(uint8_t buffer[512]);
FILE create_jpeg_file(int counter);


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover [filepath]\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *card = fopen(infile, "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Create a buffer to look for jpeg signatures
    uint8_t* buffer = malloc(sizeof(BYTE) * 512);
    int counter = 1;
    BYTE b;

    while (fread(buffer, 1, 512, card))
    {
        if (possible_image_start(buffer))
        {
            char file_name[20];
            sprintf(file_name, "%03i.jpeg", counter);
            FILE *file = fopen(file_name, "w");
            fwrite(buffer, 1, 512, file);
            fclose(file);
            counter++;
        }

    }
    fclose(card);
}


// Helper functions

// Identify possible value clusters to indicate jpeg.
bool possible_image_start(uint8_t buffer[512])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        return true;
    }
    return false;
}

// Create a file per jpeg
FILE create_jpeg_file(int counter)
{
    char file_name[20];
    sprintf(file_name, "%03i.jpeg", counter);
    FILE *file = fopen(file_name, "w");
    fclose(file);
    return *file;
}
