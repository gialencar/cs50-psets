#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // store an integer betwen 1 and 8, inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int line = 1; line <= height; line++)
    {
        // first pyramid
        for (int spaces = height - line; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (int hash = line; hash > 0; hash--)
        {
            printf("#");
        }

        // spacing
        printf("  ");

        // second pyramid
        for (int hash = line; hash > 0; hash--)
        {
            printf("#");
        }

        printf("\n");
    }

}