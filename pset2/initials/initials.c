#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Full Name: ");
    printf("%c", toupper(s[0]));
    int n = 0;
    int i = 0;
    while (s[n] != '\0')
    {
        if(s[i]==' ')
        {
            printf("%c\n", toupper(s[i+1]));
        }
        i++;
    }
}

