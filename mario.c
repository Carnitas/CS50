#include <cs50.h>
#include <stdio.h>

void print_offset(int space);
void print_row(int height);

const int n;

int main(void)
{
    int n = get_int("Height? ");
    // for (int i = 0; i < n; i++)
    while ( n > 0)
    {
        for (int j = 0; j < n ; n--)
        {
            print_offset(n - 1);
        }
        
    }
}

void print_row(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}

void print_offset(int space)
{
    for (int j = 0; j < space; j++)
    {
        printf(" ");
    }
    print_row(space);
}
