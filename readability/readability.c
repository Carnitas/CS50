#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
void print_single_word(string text);

int main(void)
{
    string text = get_string("Enter text: ");
    print_single_word(text);
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
