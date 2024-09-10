#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {

//     // Open the memory card

//     // While there's still data left to read from the memory card

//     // Create JPEGs from the data
// }

// Variables
typedef uint8_t BYTE;

// Prototypes
void possible_image_start(uint8_t buffer[512]);


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
    uint8_t buffer[512];


    while (fread(&buffer, 512, 1, card))
    {
        possible_image_start(buffer);
    }

    fclose(card);
}


// Helper functions

// Identify possible value clusters to indicate jpeg.
void possible_image_start(uint8_t buffer[512])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        printf("Possible image start\n");
    }
}
