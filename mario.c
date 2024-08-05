#include <cs50.h>
#include <stdio.h>

void print_block(int height);
void print_space(int height);

int main(void)
{
    int n;
    do
    {
        n = get_int("height? ");
    } 
    while (n < 1);
    
    // I want to decay the number first, 3 > 1
    for (int i = n; i > 0; i--)
    {
        {
            // I want spaces that count down 2 spaces #, then 1 space #, then no space
            print_space(i);
            // I want to print 1 block (see height + 1), then 2, then 3
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
    // We remove one from height so the lowest line has no leading space
    for (int i = height - 1; i > 0; i--)
    // This for loop is the same as main but I can't figure out how to reduce them
    {
        printf(" ");
    }
}
