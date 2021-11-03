#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Initialize an Int n
    int n;
    // Stores an integer between 1 and 8, inclusive
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // prints the piramid with height and width of n
    for (int i = 0; i < n; i++)
    {
        for (int spaces = (8 - n); spaces <= (6 - i); spaces++)
        {
            printf(" ");
        }

        for (int p = 0; p <= i; p++)
        {
            printf("#");
        }

        printf("\n");
    }
}
