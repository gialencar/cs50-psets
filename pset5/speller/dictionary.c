// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// prototypes
void destroy(node *list);

// Number of buckets in hash table
const unsigned int N = 12000;

// Number of words in the dictionary
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // use word hash to access hash table at that position
    node *probe = table[hash(word)];

    while (probe != NULL)
    {
        // compare words
        if (strcasecmp(word, probe->word) == 0)
        {
            return true;
        }
        // point probe to next node
        probe = probe->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
/***************************************************************************************
*    Using Djb2 algorithm
*    By Dan Bernstein
*    Available at: http://www.cse.yorku.ca/~oz/hash.html
***************************************************************************************/
    unsigned int hash = 5381;
    int c;

    while ((c = tolower(*word++)))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char *word = malloc(sizeof(char) * LENGTH + 1);

    // read strings from file one at a time
    // and create a new node for each word
    while (fscanf(dict, "%s", word) != EOF)
    {
        // create a new node and copy word into it
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // hash word to get a hash value
        unsigned int h = hash(word);

        // insert node into hash table at that location
        n->next = table[h];
        table[h] = n;

        // update word count
        word_count++;
    }

    free(word);
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // prepare to free linked lists
    // node *llist = NULL;
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            destroy(table[i]);
        }

    }
    return true;
}


void destroy(node *list)
{
    // base case: if reached a null pointer, stop
    if (list == NULL)
    {
        return;
    }

    // destroy the rest of the list
    else
    {
        destroy(list->next);
    }
    // free current node
    free(list);
}