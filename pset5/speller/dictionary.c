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

#define ALPHABET_SIZE 26 //26 lowercase and 26 uppercase letters

// Parameters
#define false 0
#define true 1

struct trie tree;

struct trie_node
{
    char *value;
    struct trie_node *children[ALPHABET_SIZE * 2]; // 2= 1 set of 26 uppercase, 1 set of 26 lowercase
};

struct trie
{
    struct trie_node root;
};

// Change a character to an integer (a-z =  0 - 25 || A-Z = 26 - 51)
int letterInt(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter - 'A' + 26;  // 26-51
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        return letter - 'a' // 0-25
    }
    return -1; // keep going
}

// Defines an invalid character within a word (based on its index)
void wrongWord(const char *word, int index)
{
    printf(" the word: \"%s\"\n", word);
    printf("    ");
    int i;
    for (i = 0; i < index; i++)
    {
        printf(" ");
    }
    printf("^\n");
}

// Puts a words into the trie table
int trieAdd(struct trie_node *node, const char *word, char *description)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        int letter = letterInt(word[i]);
        if (letter == -1)
        {
            // If the character in the string is invalid
            printf("The word was not inserted into the trie because it was invalid \n");
            wrongWord(word, i);
            printf(" description: \"s\"\n", description);
            return false;
        }
        // Setting up Trie table (node is parent, letter is children)
        struct trie_node *parent = node;
        node = node->children[letter];

        if (!node)
        {
            node = malloc(sizeof(struct trie_node));
            parent->children[letter] = node;
        }
    }

    // Allocating memory to each character, not word (saves memory)
    int len = strlen(description);
    node->value = malloc(len +1);
    strncopy(node->value, description, len);
    return true;
}

// Moving through Trie Table from node (root) and finds string of word description based on letters (children)
char *trie_get(struct trie_node *node, const char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++
    {
        int letter = letterInt(word[i]);
        if (letter == -1)
        {
            return false; // word found
        }

        node = node->children[letter];
        if(!node)
        {
            return false; // word not found
        }
    }
    return node->value;
}


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
