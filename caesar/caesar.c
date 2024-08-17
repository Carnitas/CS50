#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prototypes
void cipher_text_rotation(string plaintext);
int compute_rotation_value(int key_value);
bool only_digits(string);

int main(int argc, string argv[])
{
    const string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar [number]\n");
        return 1;
    }

    const int key_value = atoi(argv[1]);
    const int rotation_value = compute_rotation_value(key_value);
    if (only_digits(key))
    {
        printf("Integer from key: %i\n", key_value);
        printf("Rotation value: %i\n", rotation_value);
    }

    const string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    cipher_text_rotation(plaintext);
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

void cipher_text_rotation(string plaintext)
{
    const size_t n = strlen(plaintext);
    int c = 0;
    for (size_t i = 0; i < n; i++)
    {
        c = (plaintext[i] - 0);
        // int rotate_ciphertext = (c + 26);
        if (c > 90)
        {
            int loop_around = (c % 26) + 64;
            printf("%c", loop_around);
            
        }
        else
        {
            printf("%c", c);   
        } 
    }
    printf("\n");
}
