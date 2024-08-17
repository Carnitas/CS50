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
bool string_checker(string input);
int summed_value(string input);

// Helper arrays
const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Require alphabetic characters for input
    string input1;
    string input2;
    do
    {
        input1 = get_string("Player 1's word: ");
        input2 = get_string("Player 2's word: ");
    }
    while (string_checker(input1) && string_checker(input2));

    // Let's get a sum for each player's word
    const int input1_sum = summed_value(input1);
    const int input2_sum = summed_value(input2);
    
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
        printf("Tie!\n");
    }
}

// helper functions
// Sum the value of a word
int summed_value(string input)
{
    int score = 0;
    for (size_t i = 0, n = strlen(input); i < n; i++)
    {
        score += matched_value(input[i]);
    }
    return score;
}
// From a character, return its corresponding int value
int matched_value(char letter)
{
    int points_per_letter = 0;
    // n = (26 - 1) is dumb, but there are 26 letters in the alphabet and I didn't
    // want to make an off-by-one error as we went along.
    for (int i = 0, n = 26; i < n; i++)
    {
        // In order to avoid duplicate arrays, make all characters uppercase
        if (letters[i] == toupper(letter))
        {
            points_per_letter += values[i];   
            break;
        }
    }
    return points_per_letter;
}

// Reject non-alphabetic inputs
bool string_checker(string input)
{
    for (size_t i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]))
        {
            printf("Only letters are allowed.\n");
            return false;
        }
    }
    return true;
}
