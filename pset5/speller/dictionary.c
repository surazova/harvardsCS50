/******Implements a dictionary's functionality******/

// Main functionality added here
// Load: Loading the dictionary file (a text file that contians words and is a reference where the certain )
// Spelling: Is correct if the word is in the dictionary
// Unload: unloads or frees the memory and the dictionary that was allocated to being used to store the words from the dictionary
// Size: Checks the number of words on the dictionary file
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

unsigned int total_words = 0;

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
            {
                // pointer is set to the word
                mov -> word_exists = true;

                fclose(dict);

                return true;
            }
            // Position needs to be between 0 - 26 (a - b)
            if (position >= 0 && position <= 26)
            {
                if (mov -> children[position] == NULL)
                {
                    // Move to a new node
                    mov -> children[position] = null_node(mov -> children[position]);
                }

                // moving mov to next node
                mov = mov -> children[position];
            }
        }

        else
        {
            mov -> word_exists = true;

            total_words++;

            // come back to root node
            mov = root;
        }
    }

    // Error checking
    if (ferror(dict))
    {
        // close file
        fclose(dict);
        printf("There was an error!\n");
        return false;
    }

    // close file
    fclose(dict);

    // dictionary loads = true
    return true;
}

/***** PRESENT NUMBER OF WORDS IN DICTIONARY ****/
unsigned int size(void)
{
    // dictionary was loaded = return words
    if (&load)
        return total_words;
    else
        return 0;
}

bool unload(void)
{
    // free up the memory (malloc) node
    free_node(root);
    return true;
}

// Void function: accepts a node pointer
void free_node(node *move)
{
    for (int i = 0; i < 27; i++)
    {
        // Pointer set to children
        if (move -> children[i])
            free_node(move -> children[i]);

    }
    free(move);
}

/****** LETTER POSITIONS ******/
int alpha_index(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return letter - 'a';
    else if (letter >= 'A' && letter <= 'Z')
        return letter - 'A';
    else
        return 26;
}


node *null_node(node *node_pointer)
{
    node_pointer = malloc(sizeof(node));
    // If the pointer is NULL, return NULL
    if (node_pointer == NULL)
        return NULL;

    // children node = null
    for (int i = 0; i < 27; i++)
        node_pointer -> children[i] = NULL;

    node_pointer -> word_exists = false;

    // Return the node
    return node_pointer;
}


/****** TESTING ******/
// To make: make speller
// To clear: make clean
// Implementation: ./speller texts/lalaland.txt

// WORDS MISSPELLED:     955
// WORDS IN DICTIONARY:  143091
// WORDS IN TEXT:        17756
// TIME IN load:         0.18
// TIME IN check:        0.02
// TIME IN size:         0.00
// TIME IN unload:       0.12
// TIME IN TOTAL:        0.32