#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
void cipher_text_rotation(string plaintext, int rotation_value);
void lower_case_rotation(int c, int key_value);
bool only_digits(string);
void upper_case_rotation(int c, int key_value);

int main(int argc, string argv[])
{
    // Confine inputs to a single real number
    const string key = argv[1];
    if (argc != 2 || (!only_digits(key)))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    const int key_value = atoi(argv[1]);
    const int rotation_value = key_value % 26;
    const string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    cipher_text_rotation(plaintext, rotation_value);
}

// Required by the problem set
bool only_digits(string key)
{
    const size_t n = strlen(key);
    for (size_t i = 0; i < n; i++)
    {
        if (isdigit(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// Here's where we determine which rotation to apply based on character number
// in the standard ASCII chart.
void cipher_text_rotation(string plaintext, int rotation_value)
{
    const size_t n = strlen(plaintext);
    int c = 0;
    for (size_t i = 0; i < n; i++)
    {
        c = (plaintext[i] - 0);
        if (65 <= c && c <= 90)
        {
            upper_case_rotation(c, rotation_value);
        }
        else if (97 <= c && c <= 122)
        {
            lower_case_rotation(c, rotation_value);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

// Here's what happens for uppercase
void upper_case_rotation(int c, int rotation_value)
{
    int upper_cipher = c + rotation_value;
    if (upper_cipher > 90)
    {
        printf("%c", (upper_cipher - 26));
    }
    else
    {
        printf("%c", upper_cipher);
    }
}

// Here's what happens for lowercase
void lower_case_rotation(int c, int rotation_value)
{
    int lower_cipher = c + rotation_value;
    if (lower_cipher > 122)
    {
        printf("%c", (lower_cipher - 26));
    }
    else
    {
        printf("%c", lower_cipher);
    }
}
