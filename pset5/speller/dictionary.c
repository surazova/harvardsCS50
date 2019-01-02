// Implements a dictionary's functionality
// Main functionality added here
// Load: Loading the dictionary file (a text file that contians words and is a reference where the certain )
// Spelling: Is correct if the word is in the dictionary
// Unload: unloads or frees the memory and the dictionary that was allocated to being used to store the words from the dictionary
// Size: Checks the number of words on the dictionary file
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 1985

// Create a pointer for a linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
    node;

// Hash prototype
usingned long hash(char *str);

// Set the pointer to the hash table
node *hashtable[HASHTABLE_SIZE];

// Counter for the words in size
int word_count = 0;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Change the word to lowercase
    int in = strlen(word);
    char copy[n + 1];

    // Add null
    copy[n] = '\0';

    for(int i = 0; i < n; i++)
    {
        copy[i] = tolower(word[i]);
    }

    // Obtain index of word
    int index = hash(copy) % HASHTABLE_SIZE;

    // Head of the linked list
    node* head = hashtable[index];

    if(head != NULL)
    {
        // Cursor
        node* cursor = head;

        // Use the linked list
        while(cursoe !=NULL)
        {
            if(strcmp(copy, cursor->word) == 0)
            {
                //Return true if the word matches in dictionary
                return true;
            }

            // If not matching, move the cursor to the next linked list
            cursor = cursor->next;
        }
    }
    return false;
}


                    // TODO: LOAD

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary to read only
    FILE* file = fopen(dictionary, "r");

    // If the dictionary is empty
    if (file == NULL)
    {
        fprint(stderr, "Could not open file %s. \n", dictionary);
        return false;
    }

    // Set buffer to store an output word
    char buffer[LENGTH + 1];

    int n = LENGTH + 2;

    // loop through the dictionary until a null character
    while (fgets(buffer, n, file) != NULL)
    {

        // add null terminator to the end of the word
        buffer[strlen(buffer) - 1] ='\0';

        //hash the word
        int index = hash(buffer) % HASHTABLE_SIZE;

        // Create a temporay node
        node* temp = malloc(sizeof(node));

        // Test to see if node is null
        if (temp == NULL)
        {
            fclose(file);
            return false;
        }

        //Move to the enxt node in the list
        strcpy(temp -> word, buffer);
        temp -> next = hastable[index];
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
