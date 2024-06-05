#include <cs50.h>
#include <stdio.h>

// Main function
int main(void)
{
    // Get name with cs50 function
    string name = get_string("What's your name? ");

    // Print greeting with name variable
    printf("hello, %s\n", name);
}
