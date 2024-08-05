#include <cs50.h>
#include <stdio.h>

void print_offset(int space);
void print_block(int height);
void print_space(int height);

const int n;

int main(void)
{
    int n = get_int("Height? ");
    for (int i = n ; i > 0 ; i--)
    {
        {
            print_space(i);
            print_block(n - i);
        }
       
       
    }
}

void print_block(int height)
{
    for (int i = 0; i < (height + 1); i++)
    {
        printf("#");
    }
    printf("\n");
}

void print_space(int height)
{
    for ( int i = height; i > 0; i--)
    {
        printf(" ");
    }
}
