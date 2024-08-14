#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
void print_single_letter(string text);
void print_single_word(string text);
void print_single_sentece(string text);

// Global variables
int letter_count = 0;
int word_count = 0;
int sentence_count = 0;

int main(void)
{
    string text = get_string("Enter text: ");
    print_single_letter(text);
    // printf("Total letters: %i\n", letter_count);
    print_single_word(text);
    // printf("Total words: %i\n", word_count);
    print_single_sentece(text);
    // printf("Total sentences: %i\n", sentence_count);

    float L = (float) (letter_count/ word_count) * 100;
    float S = (float) (sentence_count / word_count) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Grade %i\n", (int) round(index));

}


void print_single_letter(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            // printf("%c", text[i]);
            letter_count++;
        }
    }
}

void print_single_word(string text)
{
    // int starting_index = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isspace(text[i]))
        {
            // for (int j = starting_index; j < i; j++)
            // {
            //     printf("%c", text[j]);
            // }
            // printf("\n");
            // starting_index = i + 1;
            word_count++;
        }
    }
    if (strrchr(text, '.'))
    {
        // for (int i = starting_index, n = strlen(text); i < n; i++)
        // {
        //     printf("%c", text[i]);
        // }
        word_count++;


    }
    printf("\n");
    // word_count++;
}

void print_single_sentece(string text)
{
    // int starting_index = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (ispunct(text[i]) && (text[i] != ',') && (text[i] != '\'') && (text[i] != ';') && (text[i] != '\"'))
        {
            // for (int j = starting_index; j < i; j++)
            // {
            //     printf("%c", text[j]);
            // }
            // printf("\n");
            // starting_index = i + 1;
            sentence_count++;
        }
    }
}
