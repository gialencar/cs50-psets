#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for his/her name
    string name = get_string("What is your name? ");
    // Says hello to the user
    printf("Hello, %s\n", name);
}