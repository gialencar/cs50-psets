#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt the user for the amount of change owed
    // keep track of amount of coins used
    // prints the minimum number of coins with which that change can be made

    float changeOwed;
    int coins = 0;

    do
    {
        changeOwed = get_float("Change owed: ");
    }
    while (changeOwed <= 0);

    // converts the input in dolars to cents and rounds the value to the nearest integer
    int cents = round(changeOwed * 100);


    // Quarters
    while (cents >= 25)
    {
        cents -= 25;
        coins += 1;
    }


    // Dimes
    while (cents >= 10)
    {
        cents -= 10;
        coins += 1;
    }


    // Nickels
    while (cents >= 5)
    {
        cents -= 5;
        coins += 1;
    }


    // Pennies
    while (cents >= 1)
    {
        cents -= 1;
        coins += 1;
    }

    // Prints result
    printf("%i\n", coins);

}