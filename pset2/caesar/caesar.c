#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// {
//     string s = get_string("First Name: ");
//     for(int i = 0; i < strlen(s); i++)
//     {
//         //makes the ASCII codes for a string
//         printf("%c %i\n", s[i], (int) s[i]);
//     }
// }


 int main(int argc, char* argv[])
{
    int i;
    int key = atoi(argv[1]);
    int result;
    char str[60];

for (i = 0; i < argc; i++)
{
    printf("argv[%d] = %s\n", i, argv[i]);
}

 if (argc != 2)
    {
        printf("You need to enter a key\n");
        return 1;
    }
 else
    {

        if (key == 0)
        {
            printf("Wrong key!.\n");
            return 1;
        }
    }
}