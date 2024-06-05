#include <cs50.h>
#include <stdio.h>

// Main function
int main(void)
{
    printf("PYRAMID MAKER\n");

    // Get user input for size to be integer positive not greater than 8
    int wide;
    do
    {
        wide = get_int("How tall? ");
    }
    while (wide < 1 || wide > 8);

    // Print pyramid
    for (int i = 0; i < wide; i++)
    {
        int spaces = wide - i;
        int blocks = i + 1;
        while (spaces > 1)
        {
            printf(" ");
            spaces--;
        }
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }
        printf("\n");
    }
}
