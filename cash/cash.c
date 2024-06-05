#include <cs50.h>
#include <stdio.h>

// Print the amount of coins needed to make the given amount of change in cents

// Global variables

int coin[4] = {25, 10, 5, 1};
int change;
int owed;
int cents;

int main(void)
{

    // Get non string owed positive integer.
    do
    {
        owed = get_int("Change owed:");
    }
    while (owed < 1);

    // Calculate number of coins in cents
    for (int i = 0; i < 4; i++)
    {
        while (owed >= coin[i])
        {
            owed = owed - coin[i];
            cents++;
        }
    }

    printf("%i\n", cents);
}
