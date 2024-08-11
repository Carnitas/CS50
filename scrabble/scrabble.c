// This program takes a word from each player, sums the value of the word
// according to scrabble point values, compares them, declares a winner
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Pseudo code
// Get inputs


// Figure out how to assign values to certain letters, not ascii standard
// Loop through strings-as-character-arrays, sum points

// Prototypes
int matched_value(char letter);
void string_checker(string input);

// Global variables
// These don't need to be global, but feels more readable to know what's coming.
int input1_sum = 0;
int input2_sum = 0;

// Helper arrays
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Need two do statements to protect each string
    string input1;
    do
    {
        input1 = get_string("Player 1's word: ");
        string_checker(input1);
    }
    while (strlen(input1) <= 0);

    string input2;
    do
    {
        input2 = get_string("Player 2's word: ");
        string_checker(input2);
    }
    while (strlen(input1) <= 0 && strlen(input1) <= 0);

    // Let's get a sum for each player's word
    for (int i = 0, n = strlen(input1); i < n; i++)
    {
        input1_sum += matched_value(input1[i]);
    }
    for (int i = 0, n = strlen(input2); i < n; i++)
    {
        input2_sum += matched_value(input2[i]);
    }
    
    // This is really a print debug statement, but I like it
    printf("Player 1's score: %i\n", input1_sum);
    printf("Player 2's score: %i\n", input2_sum);

    if (input2_sum > input1_sum)
    {
        printf("Player 2 wins!\n");
    }
    else if (input2_sum < input1_sum)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!");
    }
}

// helper functions
// From a character, return its corresponding int value
int matched_value(char letter)
{
    int word_sum = 0;
    // n = (26 - 1) is dumb, but there are 26 letters in the alphabet and I didn't
    // want to make an off-by-one error as we went along.
    for (int i = 0, n = (26 - 1); i < n; i++)
    {
        // In order to avoid duplicate arrays, make all characters uppercase
        if (letters[i] == toupper(letter))
        {
            word_sum += values[i];   
        }
    }
    return word_sum;
}

// Reject non-alphabetic inputs
void string_checker(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            printf("Only letters are allowed.\n");
            break;
        }
    }
}
