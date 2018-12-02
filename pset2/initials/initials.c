#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // user input
    string s = get_string("Full Name: ");

    // output to user, inital of first name, capitalized
    printf("%c", toupper(s[0]));

    // loops through the user input
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if there is a space, move to the next letter, capitalize it, and print it
        if (s[i] == ' ')
        {
            printf("%c\n", toupper(s[i+1]));
        }
    }
    return 0;
}

