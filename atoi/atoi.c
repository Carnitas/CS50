#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case. Will fire if the only character in the string is the null character.
    if (strlen(input) == 0)
    {
        return 0;
    }
    // The ascii number for the numeral zero is '48', so let's subtract that to get to our 0 integer.
    int holder = input[strlen(input) - 1] - 48;
    // Move the null character one closer to the input start.
    input[strlen(input) - 1] = '\0';
    // Add the first value to 10 times the remaining string. I don't fully understand this.
    holder += convert(input) * 10;
    return holder;
}
