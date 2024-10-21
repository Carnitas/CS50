// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase_found = false;
    bool lowercase_found = false;
    bool number_found = false;
    bool symbol_found = false;

    for (int i = 0; i < sizeof(password); i++)
    {
        if (isupper(password[i]))
        {
            uppercase_found = true;
        }
        else if (islower(password[i]))
        {
            lowercase_found = true;
        }
        else if (isdigit(password[i]))
        {
            number_found = true;
        }
        else if (ispunct(password[i]))
        {
            symbol_found = true;
        }
    }
    if (uppercase_found && lowercase_found && number_found && symbol_found)
    {
        return true;
    }
    return false;
}
