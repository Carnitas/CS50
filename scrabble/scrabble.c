#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Pseudo code
// Get inputs
// Reject non-alphabetic inputs
// Change code to uppercase
// Figure out how to assign values to certain letters, not ascii standard
// Loop through strings-as-character-arrays, sum points

// Prototypes
void matched_value(char letter);
void string_checker(string input);


// Helper arrays
char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};
int values[]   = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// In the first go we figured out how to match a letter in the letters array to the value array.
int main(void)
{
    string input;
    do
    {
        input = get_string("Got a word? ");
        string_checker(input);
        // for (int i = 0, n = strlen(input); i < n; i++)
        // {
        //     if (isalpha(input[i]) == 0)
        //     {
        //         printf("Only letters are allowed.\n");
        //         return 1;
        //     }
        // }
    }
    while (strlen(input) <= 0);

    // string s = get_string("Enter a word: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        matched_value(input[i]);
    }

}

// helper functions
void matched_value(char letter)
{
    for (int i = 0, n = 25; i < n; i++)
    {
        if (letters[i] == toupper(letter))
        {
            printf("Value: %i\n", values[i]);
        }
    }
}

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
