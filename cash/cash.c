// This program calculates the number of coins for change
#include <cs50.h>
#include <stdio.h>

// Prototypes for functions
int get_quarters(int cents);
int get_dimes(int cents);
int get_nickles(int cents);
int get_pennies(int cents);

// helper functions
void increment_coin(int coin);
void increment_leftover(int change);

int count = 0;
int leftover = 0;

int main(void)
{
    int n;
    do
    {
        n = get_int("Change in cents? ");
    }
    while (n < 1);

    if (n > 0)
    {
        printf("That's %i quarters\n", get_quarters(n));
        increment_coin(get_quarters(n));
        increment_leftover(n - (count * 25));
        // Here we process the number of dimes based on the remaining amount
        if (leftover >= 10)
        {
            printf("and %i dimes\n", get_dimes(leftover));
            increment_coin(get_dimes(leftover));
            increment_leftover(leftover -= (get_dimes(leftover) * 10));
        }
        // Here we process nickles, based on the value of leftover
        if (leftover >= 5)
        {
            printf("and %i nickles\n", get_nickles(leftover));
            increment_coin(get_nickles(leftover));
            increment_leftover(leftover -= (get_nickles(leftover) * 5));
        }

        // Given that every operation would be * or / by 1, we just return the leftover value.
        if (leftover < 5)
        {
            printf("and %i pennies\n", leftover);
            increment_coin(leftover);
            increment_leftover(leftover -= leftover);
        }

        printf("total coins: %i\n", count);
    }
}

void increment_coin(int coin)
{
    count += coin;
}

// Same as above. Initially thought I needed an extra-function counter
// But I could initialize it within main and reduce this complexity.
void increment_leftover(int change)
{
    leftover = change;
}

// The following are helper functions to process coin values
// We could probably just do the math within main
// but this facilitated the outer-function counter.
int get_quarters(int cents)
{
    return cents / 25;
}

int get_dimes(int cents)
{
    return cents / 10;
}

int get_nickles(int cents)
{
    return cents / 5;
}

// This function is useless but I added it for completeness in design.
int get_pennies(int cents)
{
    return cents;
}
