#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


// Prototypes
bool jpg_signature_found(uint8_t buffer[512]);
FILE* create_jpg_file(int counter);

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
    int counter = 0;
    bool new_jpg_found = false;
    FILE *file = NULL;

    while (fread(buffer, sizeof(buffer), 1, card))
    {

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
            fwrite(buffer, sizeof(buffer), 1, file);
        }
    }
    fclose(file);
    fclose(card);
}

// Helper functions

// Identify signature that starts a jpeg.
bool jpg_signature_found(uint8_t buffer[512])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
    {
        return true;
    }
    return false;
}

// Create a file per jpeg
FILE* create_jpg_file(int counter)
{
    char file_name[20];
    sprintf(file_name, "%03i.jpg", counter);
    FILE *file = fopen(file_name, "w");
    return file;
}
