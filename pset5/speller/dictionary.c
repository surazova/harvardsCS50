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
    for (i = 0; i < strlen(word)); i++
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

void dictionaryInit()
{
    tree = (struct trie) {}; // erases the tree
}

int dictionaryRead(const char * filename)
{
    // Opens the file
    FILE *file = fopen(filename, "r");

    if(!file)
    {
        printf("could not find or open the file! \"%s"\n", filename);
        return false;
    }

    char word[MAX_WORD_SIZE];
    char desc[MAX_DESC_SIZE];

    int count = 0;

    // word and descriton are parsed
    while (fscan(file, "%s %[^\n]", word, desc) > 1)
    {
        if (!trie_insert(&tree.root, word, desc))
        {
            fclose(file);
            return false;

        }
        else
        {
            count++;
        }
    }
    fclose(file);
    printf("parsed file \"%s\" with %i entries\n", filename, count);
    return true;
}

int dictionaryLook(const char *word, char *definition)
{
    // Check for invalid letters
    int i;
    for(i = 0; i < strlen(word); i++)
    {
        int letter = letterInt(word[i]);
        if(letter == -1)
        {
            printf("Invalid spelling!\n");
            printInvalid(word, i);
            return false;
        }
    }

    // take the string description/definition from trie table
    char *description = trie_get(&tree.root, word);

    if (!description)
    {
        return false;

    }

    // Copy the definition
    strcopy(definition, description);

    return true;
}
