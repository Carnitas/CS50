#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block size for memory card
static const int BLOCK_SIZE = 512;

// Filename length
static const char *FILENAME_FORMAT = "###.jpg";

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

    FILE *file = create_jpg_file(counter);

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (jpg_signature_found(buffer))
        {
            if (fclose(file) != 0)
            {
                printf("Unable to close current jpg.\n");
                return 3;
            }
            file = create_jpg_file(counter);
            counter++;
        }
        const int bytes_written = fwrite(buffer, 1, BLOCK_SIZE, file);
        assert(bytes_written == BLOCK_SIZE);
    }
    if (fclose(file) != 0)
    {
        printf("Unable to close last jpg.\n");
        return 4;
    }
    if (fclose(card) != 0)
    {
        printf("Unable to close memory card.\n");
        return 5;
    }
}

// Helper functions

// Identify signature that starts a jpeg.
bool jpg_signature_found(uint8_t buffer[BLOCK_SIZE])
{
    static const uint8_t BYTE_3_MASK = 0xe0;
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
        (buffer[3] & BYTE_3_MASK) == 0xe0)
    {
        return true;
    }
    return false;
}

// Create a file per jpg
FILE *create_jpg_file(int counter)
{
    char file_name[strlen(FILENAME_FORMAT)];
    sprintf(file_name, "%03i.jpg", counter);
    FILE *file = fopen(file_name, "w");
    return file;
}
