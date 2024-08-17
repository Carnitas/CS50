#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prototypes

int compute_rotation_value(int key_value);
bool only_digits(string);
int cipher_text_output(int key_value, int rotation);

int main(int argc, string argv[])
{
    const string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar [number]\n");
    }


    const int key_value = atoi(argv[1]);
    const int rotation = compute_rotation_value(key_value);
    // const int cipher_text_value = cipher_text_output(key_value, rotation);
    if (only_digits(key))
    {
        printf("Integer from key: %i\n", key_value);
        printf("Rotation value: %i\n", rotation);
        // printf("Rotation value: %i", cipher_text_value);
        
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
}

int compute_rotation_value(int key_value)
{
    const int rotation_value = key_value % 26;
    return rotation_value;
}

// int cipher_text_output(int key_value, int rotation)
// {
//     int cipher_text = 0;
//     const size_t n = strlen(key);
//     for (size_t i = 0; i < n; i++)
//     {
//         if (rotation < 26)
//         {
//             printf("Cipher key: %i", cipher_text);
//         }
//         else
//         {
//             cipher_text = rotation % 26;
//             printf("Cipher value: %i", cipher_text);
//         }
//     }
// }
