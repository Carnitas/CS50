#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {

//     // Open the memory card

//     // While there's still data left to read from the memory card

//     // Create JPEGs from the data
// }


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: Enter file path for recoverable image.\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[optind];

    // Attempt to open file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }
    else
    {
        printf("File opened!\n");
        fclose(inptr);
        return 0;
    }
}
