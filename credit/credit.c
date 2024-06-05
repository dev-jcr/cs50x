#include <cs50.h>
#include <stdio.h>

// Global variables
long number;
int lenght = 0;
int digits[100];
int digit, c, vL, vD, creditorValid;
int validLenght[3] = {13, 15, 16};
int validDigits[3] = {3, 5, 4};
string result[4] = {"AMEX\n", "MASTERCARD\n", "VISA\n", "INVALID\n"};
string creditor;
int check[3];

// Prototypes
int getDigit(long numberUsed);
int checksum(void);
int validateLenght(int q);
int validateDigits(int x);

// Execution
int main(void)
{
    // Input
    number = get_long("Number: ");
    long x = number;
    while (x > 0)
    {
        int digito = getDigit(x);
        digits[lenght] = digito;
        x = x / 10;
        lenght++;
    }
    c = checksum();
    check[0] = c;
    // printf("\nc%i", check[0]);
    vL = validateLenght(lenght);
    check[1] = vL;
    // printf("vL%i", check[1]);
    vD = validateDigits(lenght);
    check[2] = vD;
    // printf("vD%i\n", check[2]);
    if (check[2] == 10 && lenght == 15)
    {
        creditor = result[0];
    }
    else if (check[2] == 11 && lenght == 16)
    {
        creditor = result[1];
    }
    else if (check[2] == 12 && lenght == 13)
    {
        creditor = result[2];
    }
    else if (check[2] == 12 && lenght == 16)
    {
        creditor = result[2];
    }
    else
    {
        creditor = result[3];
    }
    if (check[0] >= 1 && check[1] >= 1 && check[2] >= 10)
    {
        printf("%s", creditor);
    }
    else
    {
        printf("%s", result[3]);
    }
}

int getDigit(long numberUsed)
{
    // Extracting first digit right to left
    int extracted;
    extracted = numberUsed % 10;
    return extracted;
}

int validateDigits(int x)
{
    // Check if first two numbers are valid
    int valid;
    int lastNumber = x - 1;
    int beforeLast = x - 2;

    // Evaluate if first from left number is valid
    for (int i = 2; i > 0; i--)
    {
        if (digits[lastNumber] == 3)
        {
            valid = 10;
            break;
        }
        else if (digits[lastNumber] == 5)
        {
            valid = 11;
            break;
        }
        else if (digits[lastNumber] == 4)
        {
            valid = 12;
            break;
        }
        else
        {
            valid = 0;
        }
    }
    // printf("%i", valid);

    // Evaluate if also the second one is valid
    if (valid >= 10)
    {
        for (int i = 5; i > 0; i--)
        {
            if (digits[lastNumber] == 5 && digits[beforeLast] == i)
            {
                valid = 11;
                break;
            }
            else
            {
                valid = 0;
            }
        }

        if (valid == 0)
        {
            if (digits[lastNumber] == 3 && digits[beforeLast] == 4)
            {
                valid = 10;
            }
            else if (digits[lastNumber] == 3 && digits[beforeLast] == 7)
            {
                valid = 10;
            }
            else
            {
                valid = 0;
            }

            if (valid == 0)
            {
                if (digits[lastNumber] == 4)
                {
                    valid = 12;
                }
                else
                {
                    valid = 0;
                }
            }
        }
    }
    return valid;
}

int checksum(void)
{
    /*
    Luhn's Algorithm
    Multiply everyother digit by 2 starting with the second-to last digit
    Add products digits together
    Add the sum of the sum of digits not multiplied by 2
    if total's last digit is 0 (total modulo 10 is congruent to 0) it's valid
    */
    int timesTwo;
    int timesTwoDigit;
    int sumOthers = 0;
    int digitsSum;
    int valid;
    int operation;
    for (int i = 1; i < lenght; i = i + 2)
    {
        timesTwo = digits[i] * 2;
        // printf("\nTimes Two: %i", timesTwo);
        timesTwoDigit = timesTwo;
        while (timesTwoDigit >= 10)
        {
            timesTwoDigit = timesTwo - 10;
            timesTwoDigit++;
        }
        // printf("\nTimes Two Digit: %i", timesTwoDigit);
        digitsSum = digitsSum + timesTwoDigit;
    }
    // printf("\nDigits Sum: %i", digitsSum);
    for (int i = 0; i < lenght; i = i + 2)
    {
        // printf("\nOther digit: %d", digits[i]);
        sumOthers = sumOthers + digits[i];
    }
    // printf("\nSum others: %i", sumOthers);
    operation = digitsSum + sumOthers;
    // printf("\nTotal: %i", operation);
    while (operation > 0)
    {
        operation = operation - 10;
    }
    if (operation == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    return valid;
}

int validateLenght(int q)
{
    int lenghtValid;
    // Determine if the lenght it's valid
    if (q == 13)
    {
        lenghtValid = 1;
        creditor = result[2];
    }
    else if (q == 15)
    {
        creditor = result[0];
        lenghtValid = 1;
    }
    else if (q == 16)
    {
        lenghtValid = 1;
    }
    else
    {
        lenghtValid = 0;
        creditor = result[3];
    }
    return lenghtValid;
}

/*
int getLenght(long y)
{
    // Obtain lenght of number
    int x = 0;
    do
    {
        y = y / 10;
        x++;
    }
    while (y != 0);
    return x;
}
*/
