#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// function declaration
int alphaIndex(string, int);

// user-side
int main(int argc, string argv[])
{
    // declaring two integers
    int key;
    int secret;

    // checking against the user for an input
    if (argc!= 2 || atoi(argv[1]) <= 0)
    {
        printf("Put in a command line argument!\n");
        //printf("Usage: %s k/n", argv[0]);
        return 1;
    }

    //change the key to an int
    key = atoi(argv[1]);
    string message = get_string("message: ");
    printf("secret: "); //prints the secret message after applying a key of your choosing
    secret = alphaIndex(message, key);
}

// program-side
int alphaIndex(string text, int key)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]) && islower(text[i]))  // lowercase instance
        {
            printf("%c", (((text[i] - 97) + key) % 26) + 97);  // ASCII for lower is 97 (a)
        }

        else if(isalpha(text[i]) && isupper(text[i]))  // uppercase instance
        {
            printf("%c", (((text[i] - 65) + key) % 26) + 65);  // ASCII for upper is 65 (a)
        }

        else
        {
            printf("%c", text[i]);   // not letters or numers (symbols)
        }
    }

    return 0;
}

