#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // The user must pass the key as one and only command line argument when calling the program
    if (argc < 2 || argc > 2)
    {
        printf("Error: you must pass 1 key.\n");
        return 1;
    }


    // The key must contain only decimal digits, here we check if the user passed any invalid key
    // Loops through the string
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // If the char is not a digit, show error message and terminate the program
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    // Convert the key, with is a string, to an integer
    int key = atoi(argv[1]);


    // Ask the user for the plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Iterate through the plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char character = plaintext[i];
        // If the char is a letter
        if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
        {
            int cipher_char = character + key;

            // handles uppercase letters
            if (cipher_char > 'Z' && cipher_char < 'a')
            {
                printf("%c", cipher_char - (cipher_char % 65) + (cipher_char - 91));
            }

            // handles lowercase letters
            else if (cipher_char > 'z')
            {
                do
                {
                    cipher_char = cipher_char - (cipher_char % 97) + (cipher_char - 123);
                }
                while (cipher_char > 'z');

                printf("%c", cipher_char);
            }
            else
            {
                // shifting every char by the amount of positions given by the key
                printf("%c", character + key);
            }
        }
        else
        {
            printf("%c", character);
        }
    }
    printf("\n");
}