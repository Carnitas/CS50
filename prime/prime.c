#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    const int small_primes[] = {2, 3, 5, 7};
    const int array_size = sizeof(small_primes) / sizeof(small_primes[0]);
    for (int i = 0; i < sizeof(array_size); i++)
    {
        if (number == small_primes[i])
        {
            return true;
        }
    }
    if (number == 1 || number % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i < 10; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
