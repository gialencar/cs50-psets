#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);


int main(void)
{
    // Get the text from the user
    string text = get_string("Text: ");

    // Convert the text to lowercase
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
    }

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculates averages for the formula
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // Calculates the Coleman–Liau index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Print the results
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int count_letters(string s)
{
    // iterates trough the given string and count only the letters
    int letters = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    // Counts words in the given string based on spaces
    int words = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string s)
{
    // Counts sentences in given string, using a . or a ! or a ? as separators
    int sentences = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
