// // Implements a dictionary's functionality
// // Main functionality added here
// // Load: Loading the dictionary file (a text file that contians words and is a reference where the certain )
// // Spelling: Is correct if the word is in the dictionary
// // Unload: unloads or frees the memory and the dictionary that was allocated to being used to store the words from the dictionary
// // Size: Checks the number of words on the dictionary file
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

unsigned int words_total = 0;

// True: word is in the dictionary
// False: word is not in the dictionary
bool check(const char *word)
{
    int position = 0;
    int incorrect_words = 0;
    // set pointer to the node
    mov = root;

    // char = letter
    for (int i = 0; i < strlen(word); i++)
    {
        // find the position of each letter
        position = alpha_index(word[i]);

        if (mov -> children[position] == NULL)
        {
            incorrect_words++;

            // exit
            return false;
        }
        else
        {
            // Next letter
            mov = mov -> children[position];
        }
    }

    // Next case: if true, then word is in the dictionary
    if (mov -> word_exists)
        return true;

    return false;
}

/**** ADDING DICTIONARY TO MEMORY ****/
bool load(const char *dictionary)
{
    // open, read mode
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        printf("Sorry, dictionary could not be opened\n");

        return false;
    }

    // Keeps index for current user
    int position = 0;
    char letter;

    root = null_node(mov);
    mov = root;

    // Load every word from dictionary
    while(true)
    {
        letter = fgetc(dict);

        position = alpha_index(letter);

        if (letter != '\n')
        {
            // end of file
            if (feof(dict))
        }
    }
}

// initialize and name variables
node *head = NULL;
node *hashtable[1000];
int hashtable_size = 1000;
int wordcount;

// define a hash function
int hash_function(const char* key)
{
    int index = 0;

    // traverse through the whole word of the word to be hashed
    for(int i = 0; key[i] != '\0'; i++)
    {
        // add up the index per char of the word
        index += toupper(key[i]);
    }

    // modulo the index with the hashtable_size to ensure accuracy
    // and limit the index within the size
    return index % hashtable_size;
}




/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO

    // an int variable to contain the index of the hashed word to be checked
    int hash = hash_function(word);

    // match the index of the word to be checked if there is an existing
    // index of it in the hash table
    if(hashtable[hash] == NULL)
    {
        // return false if the index of the word to be checked didn't match
        // with any existing index that has a word on it in hash table
        return false;
    }

    // if it matched, proceed to checking
    else if(hashtable[hash] != NULL)
    {

        // initialized a temp node in order to traverse through the linked-list
        node *cursor = hashtable[hash];

        // check if the current node is not empty
        while(cursor != NULL)
        {

            // compare string per string using strcasecmp
            int i;
            i = strcasecmp(cursor->word, word);
            if(i == 0)
            {
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    return false;
}


/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO

    // open dictionary file and check if it exist
    FILE *fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        return false;
    }

    // initialize words from dictionary to be temporarily written
    char word[LENGTH + 1];

    // initialize wordcount to 0 so it can be incremented later
    wordcount = 0;

    // look and scan for words in dictionary until the end of file
    while(fscanf(fp, "%s", word) != EOF)
    {

        // allocate memory to be used
        node *new_node = malloc(sizeof(node));

        // initialize the memories allocated to NULL while it wasn't used
        memset(new_node, 0, sizeof(node));

        // if the new_node wasn't properly allocated with memory, unload
        if(new_node == NULL)
        {
            unload();
            return false;
        }

        // increment wordcount everytime a word is found
        wordcount++;

        // copy the word found to word pointer of node
        strcpy(new_node->word, word);

        // hash the word copied so it can be indexed on the hash table
        int hashed = hash_function(word);

        // check if the index of the hashtable has contents
        if(hashtable[hashed] == NULL)
        {

            // if there's no content, initialized the new node as the head
            hashtable[hashed] = new_node;
            head = new_node;
        }
        else
        {

            // if there's content, rewire the new node to be the head and start
            new_node->next = hashtable[hashed];
            hashtable[hashed] = new_node;
            head = new_node;
        }
    }

    fclose(fp);
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // just return the wordcount implanted on the load function
    return wordcount;;
}


/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    // traverse through the hashtable and free its contents
    for(int i = 0; i < hashtable_size; i++)
    {
        if(hashtable[i] != NULL)
        {
            node *cursor = hashtable[i];
            while(cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);

            }
        }
    }


    return true;

}