// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

// Prototype
void replace(char* word);
void replace_char_if_necessary(char* character);

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
  for (int i = 0; word[i] != '\0'; i++)
  {
    replace_char_if_necessary(&word[i]);
  }
  printf("%s\n", word);
}


void replace_char_if_necessary(char* character)
{
  switch (*character) {
    case 'a':
    case 'A':
      *character = '6';
      break;
    case 'e':
    case 'E':
      *character = '3';
      break;
    case 'i':
    case 'I':
      *character = '1';
      break;
    case 'o':
    case 'O':
      *character = '0';
      break;
  }
}
