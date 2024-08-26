// This program takes input, found (here)[https://cs50.harvard.edu/x/2024/psets/2/readability/#how-to-test]
// and returns an average reading level.

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
float count_single_letters(string text);
float count_single_words(string text);
float count_sentences(string text);

int main(void)
{
    const string text = get_string("Enter text: ");

    float letter_count = count_single_letters(text);
    float word_count = count_single_words(text);
    float sentence_count = count_sentences(text);

    // Kept these to track how I printed characters
    // printf("Total letters: %f\n", letter_count);
    // printf("Total words: %f\n", word_count);
    // printf("Total sentences: %f\n", sentence_count);

    const float L = letter_count/word_count * 100;
    const float S = sentence_count/word_count * 100;

    const double index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

// Count alphabetic characters
float count_single_letters(string text)
{
    const size_t num_chars = strlen(text);
    float letter_count = 0.0;
    for (size_t i = 0; i < num_chars; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// Count words
float count_single_words(string text)
{
    // The index stuff was for printing individual words so that I could count
    // from the space to the next space.

    // int starting_index = 0;
    float word_count = 0.0;
    for (int i = 0, n = (int) strlen(text); i < n; i++)
    {

        if (isspace(text[i]))
        {
            // Just for printing out the words. Only really need the count.
            // for (int j = starting_index; j < i; j++)
            // {
            //     printf("%c", text[j]);
            // }
            // printf("\n");
            // starting_index = i + 1;
            word_count++;
        }
    }
    // Since I'm just counting up to spaces, needed to catch the last word.
    if (strrchr(text, '.'))
    {
        // More print debugging.
        // for (int i = starting_index, n = strlen(text); i < n; i++)
        // {
        //     printf("%c", text[i]);
        // }
        word_count++;
    }
    return word_count;
}

float count_sentences(string text)
{
    // Same as above, promote the starting index to one after a period character.
    // int starting_index = 0;
    float sentence_count = 0.0;
    for (int i = 0, n = (int) strlen(text); i < n; i++)
    {
        // Check the ways a sentence can end in English syntax.
        if (strchr(".!?", text[i]))
        {
            // print debugging
            // for (int j = starting_index; j < i; j++)
            // {
            //     printf("%c", text[j]);
            // }
            // printf("\n");
            // starting_index = i + 1;
            sentence_count++;
        }
    }
    return sentence_count;
}
