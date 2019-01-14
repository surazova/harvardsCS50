// Declares a dictionary's functionality

// #ifndef DICTIONARY_H
// #define DICTIONARY_H

// #include <stdbool.h>

// // Maximum length for a word
// // (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
// #define LENGTH 45

// // Prototypes
// bool check(const char *word);
// bool load(const char *dictionary);
// unsigned int size(void);
// bool unload(void);

// #endif // DICTIONARY_H


/*******Defined functionality for the trie table******/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_WORD_SIZE   40
#define MAX_DESC_SIZE  200

void dictionaryInit();

int dictionaryRead(const char * filename);

int dictionaryLook(const char * word, char * meaning);

#endif