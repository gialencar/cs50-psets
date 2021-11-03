#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int get_lenght(long number);

int main(void)
{
    // TEST NUMBER
    // 4003600000000014

    // Prompt the user for a credit card number
    unsigned long cardnum = get_long("Number: ");
    unsigned long d;
    int lenght = get_lenght(cardnum);
    int sum = 0;


    // Calculate checksum

    /* debug
    printf("10 = %lu \n", cardnum % 10);
    printf("100 = %lu \n", cardnum % 100);
    printf("Lenght = %i \n", lenght);
    printf("        ");
    */

    // iterate through every other digit, starting from the second to last
    for (int i = 1; i < lenght; i += 2)
    {
        // get pos
        d = cardnum / pow(10, i);
        // printf("        %lu", d);

        // get digit
        d = d % 10;
        // printf("    %lu\n", d);

        // Multiply by 2 and add individual digits to sum
        d = d * 2;
        while (d > 0)
        {
            int y = d % 10;
            sum += y;
            d /= 10;
        }
    }

    // Add remaining card digits to sum
    for (int i = 0; i < lenght; i += 2)
    {
        d = cardnum / pow(10, i);
        // printf("        %lu", d);

        d = d % 10;
        // printf("    %lu\n", d);

        // add
        sum += d;
    }


    // Validate
    if (sum % 10 == 0)
    {
        // Check for card leght and starting digits

        if (lenght == 13 || lenght == 15 || lenght == 16)
        {
            // Get first digits
            char first_digits[3];
            int counter = 0;
            for (int i = lenght - 1; i >= lenght - 2; i--)
            {
                d = cardnum / pow(10, i);
                d = d % 10;
                sprintf(&first_digits[counter], "%lu", d);
                counter++;
            }
            // printf("%s\n", first_digits);


            // AMEX
            if (!strcmp(first_digits, "34") || !strcmp(first_digits, "37"))
            {
                printf("AMEX\n");
            }


            // MASTERCARD
            else if (!strcmp(first_digits, "51") || !strcmp(first_digits, "52") || !strcmp(first_digits, "53") || !strcmp(first_digits, "54")
                || !strcmp(first_digits, "55"))
            {
                printf("MASTERCARD\n");
            }


            // VISA
            else if (!strncmp(first_digits, "4", sizeof(char)))
            {
                printf("VISA\n");
            }


            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}


int get_lenght(long number)
{
    int lenght = 0;
    do
    {
        number /= 10;
        lenght++;
    }
    while (number != 0);

    return lenght;
}