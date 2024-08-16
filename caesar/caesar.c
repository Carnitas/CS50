#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prototypes
<<<<<<< HEAD
<<<<<<< HEAD
=======
int compute_rotation_value(int key_value);
>>>>>>> 5c56043 (Figure out cipher function)
bool only_digits(string);
int cipher_text_output(int key, int rotation);


// Pseudocode
<<<<<<< HEAD
// Rewrite int main void to accept commandline arguments
// Return the string 'Key: %i', string
// Figure out how to use a boolean to check if the whole string is a number
=======
bool only_digits(string key);
>>>>>>> 1245acc (Update gitignore, add cli arg)
=======
// Figure out rotation cipher, don't try to do it all at once.
>>>>>>> 5c56043 (Figure out cipher function)

int main(int argc, string argv[])
{
    const string key = argv[1];
<<<<<<< HEAD
    if (argc != 2)
    {
        printf("Usage: ./caesar [number]\n");
    }


    const int key_value = atoi(argv[1]);
    const int rotation = compute_rotation_value(key_value);
    const int cipher_text_value = cipher_text_output(key_value, rotation);
    if (only_digits(key))
    {
        printf("Integer from key: %i\n", key_value);
        printf("Rotation value: %i", cipher_text_value);
        
    }
    
}

// Required by the problem set
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

int compute_rotation_value(int key_value)
{
    const int rotation_value = key_value % 26;
    printf("Rotation value: %i", rotation_value);
    return rotation_value;
}

int cipher_text_output(int key, int rotation)
{
    int cipher_text = 0;
    const size_t n = strlen(key);
    for (size_t i = 0; i < n; i++)
    {
        if (rotation < 26)
        {
            printf("Cipher key: %i", cipher_text)
        }
        else
        {
            cipher_text = rotation % 26;
            printf("Cipher value: %i", cipher_text);
        }
    }
}
