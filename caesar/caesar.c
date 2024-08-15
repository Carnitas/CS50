#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
<<<<<<< HEAD
bool only_digits(string);

// Pseudocode
// Rewrite int main void to accept commandline arguments
// Return the string 'Key: %i', string
// Figure out how to use a boolean to check if the whole string is a number
=======
bool only_digits(string key);
>>>>>>> 1245acc (Update gitignore, add cli arg)

int main(int argc, string argv[])
{
    const string key = argv[1];
<<<<<<< HEAD
    if (argc != 2)
    {
        printf("Usage: ./caesar [number]\n");
    }


    if (only_digits(key))
    {
        printf("Here's your key: %s\n", argv[1]);
        return 0;
    }
}

bool only_digits(string key)
{
    const size_t n = strlen(key);
    for (size_t i = 0; i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Please try again and enter one number.\n");
            return false;
        }
    }
    return true;
=======
    do 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    while (argc != 2);

    // only_digits(key);

    printf("Cipher key: %s\n", argv[1]);
    return 0;
}

// Helper functions
bool only_digits(string key)
{ 
    const size_t n = strlen(key);
    for (size_t i = 0; i < n; i++ )
    {
        if (isdigit(key[i]))
        {
            return true;
        }
    }
    return false;
>>>>>>> 1245acc (Update gitignore, add cli arg)
}
