// The structure of this program is set by CS50 so we've gotta work into it

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
const int MAX = 9;

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
// Set a magic number to bypass an error. '9' should be MAX.
candidate candidates[9];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate winner = {.name="", .votes=0};
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count - 1; j++)
        {
            if (candidates[j].votes > candidates[j+1].votes)
            {
                winner = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = winner;
            }
        }
    }
    for (int k = 0; k < candidate_count; k++)
    {
        const int most_votes = candidates[candidate_count - 1].votes;
        if (candidates[k].votes == most_votes)
        {
            printf("%s\n", candidates[k].name);
        }
    }
}
