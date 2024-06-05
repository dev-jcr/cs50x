#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get input
    int height;
    do
    {
        height = get_int("Pyramid height: ");
    }
    while (height < 1 || height > 8);

    /*  Loop to print pyramid.
    1 added to height to be able to use it correctly in the loop
    1 removed from the same variable later for the same reason
    */
    height = height + 1;
    for (int i = 1; i < height; i++)
    {
        // Variables.
        int spaces = height - 1 - i;
        int blocks = i;
        int repeat = 0;

        // Print spaces
        for (int e = 0; e < spaces; e++)
        {
            printf(" ");
        }

        // Print first line of blocks
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
            repeat++;
        }

        // Separation spaces
        printf("  ");

        // Print second line of blocks
        for (int k = repeat; k > 0; k--)
        {
            printf("#");
        }

        // Next line of blocks
        printf("\n");
    }
}
