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

    if (n > 25)
    {
        printf("That's %i quarters\n", get_quarters(n));
        increment_coin(get_quarters(n));
        increment_leftover(n - (count * 25));
    if (leftover >= 10)
    {
        printf("and %i dimes\n", get_dimes(leftover));
        increment_coin(get_dimes(leftover));
        increment_leftover(leftover -= (get_dimes(leftover) * 10));
    }
    if (leftover >= 5)
    {
        printf("and %i nickles\n", get_nickles(leftover));
        increment_coin(get_nickles(leftover));
        increment_leftover(leftover -= (get_nickles(leftover) * 5));
    }
    if (leftover)
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

void increment_leftover(int change)
{
    leftover = change;
}

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

int get_pennies(int cents)
{
    return cents;
}

