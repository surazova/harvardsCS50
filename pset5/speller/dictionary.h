// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_WORD_SIZE   40
#define MAX_DESC_SIZE  200

void dictionaryInit();

int dictionaryRead(const char * filename);

int dictionaryLook(const char * word, char * meaning);

// // Prototypes
// bool check(const char *word);
// bool load(const char *dictionary);
// unsigned int size(void);
// bool unload(void);


#endif