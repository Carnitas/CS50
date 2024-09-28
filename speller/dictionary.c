// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 200007;

// Hash table
node *table[N];

// Dictionary word count
int dict_word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    const int x = hash(word) % N;
    return (table[x] != NULL && strcasecmp(table[x]->word, word) == 0);
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int ascii_sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        ascii_sum += (int)tolower(word[i]);
    }
    return ascii_sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    char buffer[LENGTH + 1];

    while (fscanf(source, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));

        strcpy(n->word, buffer);
        n->next = NULL;

        const int x = hash(buffer);
        n->next = table[x];
        table[x] = n;
        dict_word_count += 1;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
