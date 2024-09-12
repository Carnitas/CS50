#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Block size for memory card
const int BLOCK_SIZE = 512;

// Filename length
const char *FILENAME_FORMAT = "###.jpg";

// Prototypes
bool jpg_signature_found(uint8_t buffer[BLOCK_SIZE]);
FILE *create_jpg_file(int counter);

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
    uint8_t buffer[BLOCK_SIZE];
    int counter = 0;

    FILE *file = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, card))
    {
        // Initialize boolean for flag when we find a new image
        bool new_jpg_found = false;

        if (new_jpg_found)
        {
            new_jpg_found = false;
        }

        if (jpg_signature_found(buffer))
        {
            if (file != NULL)
            {
                fclose(file);
            }
            file = create_jpg_file(counter);
            counter++;
            new_jpg_found = true;
        }

        if (file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, file);
        }
    }
    fclose(file);
    fclose(card);
}

// Helper functions

// Identify signature that starts a jpeg.
bool jpg_signature_found(uint8_t buffer[BLOCK_SIZE])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
        (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
    {
        return true;
    }
    return false;
}

// Create a file per jpeg
FILE *create_jpg_file(int counter)
{
    char file_name[strlen(FILENAME_FORMAT)];
    sprintf(file_name, "%03i.jpg", counter);
    FILE *file = fopen(file_name, "w");
    return file;
}
