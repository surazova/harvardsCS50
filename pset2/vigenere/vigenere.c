#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // declare three variables, all equal to 0
    int j;
    int k;
    int l = 0;

    // check against user for one command line argument
    if (argc != 2)
    {
        printf("Try Again\n");
        return 1;
    }

    string s = (argv[1]);
    // Make sure command line argument is alpha
    // isalpha() takes a single argument in the form of an integer and returns an integer value
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == false)
        {
            printf("Try that again\n");
            return 1;
        }
    }

    // Get user input string
    string plainText = get_string("plaintext: ");

    // Printing the cypher text
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plainText); i++)
    {
        // Encrypting lower case
        if islower(plainText[i])
        {
            j = (l % strlen(s));
            k = (tolower(s[j]) - 97);
            printf("%c", (((plainText[i] + k) - 97) % 26) + 97);
            l += 1;
        }

        // Encrypting upper case
        if isupper(plainText[i])
        {
            j = (l % strlen(s));
            k = (tolower(s[j]) - 97);
            printf("%c", (((plainText[i] + k) - 65) % 26) + 65);
            l += 1;
        }

        // other print
        else
        {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
    return 0;
}