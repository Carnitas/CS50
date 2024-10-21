// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

// Prototype
void replace(char*);

typedef struct {
    char letter;
    char symbol;
} leet_map;

leet_map map[8] = {
    {'A', '6'},
    {'a', '6'},
    {'E', '3'},
    {'e', '3'},
    {'I', '1'},
    {'i', '1'},
    {'O', '0'},
    {'o', '0'},
};

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./no-vowels word\n");
        return 1;
    }
    replace(argv[1]);
}

void replace(char* word)
{
    const int map_size = sizeof(map) / sizeof(map[0]);
    for (int i = 0; word[i] != '\0'; i++)
    {
       if (map.contains(word[i])) {
          word[i] = map[word[i]].symbol;
       }
    }
    printf("%s", word);
}
