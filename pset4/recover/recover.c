#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// string is changed to char *argv
int maiin(int argc, cahr *argv[])
{
    // check for only 1 command line argument
    //FILE *file = fopen(argv[1], "r");
    if (argc != 2)
    {
        fprintf(stderr, "Please enter file name.\n");
        return 1;
    }
    //Open the file entered into the command line
FILE *file = fopen(argv[1], "r");
//If the file does not exist, throw an error
if (file == NULL)
{
fprintf(stderr, "Could not open %s.\n", argv[1]);
return 1;
}

}


// iterate through the array
// look throug the JPEG signatures
// Leading format: 0xff 0xd8 0xff
// Find a signature, open a new file for writing and fill the file with bytes
// Once a new signature is found, close the file and then repeat last step
// Beginning of each image is the first 4 bytes of each chunk of 512 bytes
    // Check of buffer[0]
    // buffer[1]
    // buffer[2]
    //buffer[3]
// No JPEGs can be larger than 512B
// Slack space is represented by 0