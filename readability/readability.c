#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
void print_single_word(string text);

// Global variables
int word_count = 0;

int main(void)
{
    string text = get_string("Enter text: ");
    print_single_word(text);
    printf("Total words: %i\n", word_count);
}


void print_single_word(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            for (int j = 0; j < i; j++)
            {
                printf("%c\n", text[i]);
                word_count++;
                break;
            }
        }
        else if (isalpha(text[i]))
        {
                printf("%c", text[i]);
        }
    }
    printf("\n");
}
