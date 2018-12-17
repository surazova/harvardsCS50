#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Enter only 1 command line argument
    if (argc != 2)
{

    fprintf(stderr, "Please enter a file name to open.\n");
    return 1;
}

    // File that is entered will open
    FILE *file = fopen(argv[1], "r");

    //If the file does not exist, error
    if (file == NULL)
    {
    fprintf(stderr, "Could not open %s.\n", argv[1]);
    return 1;
    }

    // Picture output
    FILE *img = NULL;
    // buffer and filename arrays

    unsigned char buffer[512];
    char filename[8];
    //Set counter for filename
    int counter = 0;
    //Set flag
    bool flag = false;
    //Read the file
    while (fread(buffer, 512, 1, file) == 1)
    {
    //Check if we are at the beginning of a JPEG
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
    //Close current JPEG, so we can start reading the next
    if (flag == true)
    {
    fclose(img);
    }
    //Condition for found JPEG
    else
    {
    flag = true;
    }
    sprintf(filename, "%03i.jpg", counter);
    img = fopen(filename, "w");
    counter++;
    }
    if (flag == true)
    {
    fwrite(&buffer, 512, 1, img);
    }
    }
    //Close all files
    fclose(file);
    fclose(img);
    //Success
    return 0;
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