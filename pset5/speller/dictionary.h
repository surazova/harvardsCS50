// // Declares a dictionary's functionality

// #ifndef DICTIONARY_H
// #define DICTIONARY_H

// #define MAX_WORD_SIZE   40
// #define MAX_DESC_SIZE  200

// void dictionaryInit();

// int dictionaryRead(const char * filename);

// int dictionaryLook(const char * word, char * meaning);

// // // Prototypes
// // bool check(const char *word);
// // bool load(const char *dictionary);
// // unsigned int size(void);
// // bool unload(void);


// #endif

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H