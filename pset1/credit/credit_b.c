#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


string get_digits(char *card_number);


int main(void)
{
    // initialize variables
    string card_num;
    int sum_mult = 0;

    // Prompt the user for a credit card number
    card_num = get_string("Number: ");

    // get every other digit, starting from the second to last
    string digits = get_digits(card_num);
    printf("%s\n", digits);

    // multiply each of the digits by 2, and add them together
    for (int i = 0; i < strlen(digits); i++)
    {
        int c = digits[i] - '0';
        printf("%i\n", c);
        if (c >= 5)
        {
            char ch[2];
            sprintf(ch, "%i", c * 2);
            for (int j = 0; j < strlen(ch); j++)
            {
                sum_mult += ch[j] - '0';
            }
        }
        else
        {
            sum_mult += c * 2;
        }
    }



    for (int i = strlen(card_num) - 1; i >= 0; i -= 2)
    {
        sum_mult += card_num[i] - '0';
    }

    if (sum_mult % == 0)
    {
        if (card_num[0:2])
    }


    printf("%i\n", sum_mult);

}


string get_digits(char *card_number)
{
    string digits = malloc(round(sizeof(card_number) / 2));

    int counter = 0;
    for (int i = strlen(card_number) - 2; i >= 0; i -= 2)
    {
        digits[counter] = card_number[i];
        counter++;
    }
    return digits;
}