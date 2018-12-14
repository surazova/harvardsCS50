// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // Get n from user
    int n = atoi(argv[1]);

    // 1st argument: n must be equal to or less than a 100
    if (n =< 100)
    {
        printf("The resize vlaue must be between 0 and 100\n");

        return 5;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    // Added bfR (for the output)
    BITMAPFILEHEADER bf, bfR;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfR = bf;

    // read infile's BITMAPINFOHEADER
    // Adding biR for output
    BITMAPINFOHEADER bi, bfR;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    biR = bi;

    // Setting the output header files
    biR.biWidth = bi.biWidth * n;
    biR.biHeight - bi.biHeight * n;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Adding the padding specifications for the infile and outfile
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Adding the new image size
    bfR.bfSize = 54 + biR.biWidth * abs(biR.biHeight) * 3 + abs(biR.biHeight) * outPadding;
    biR.biSize = ((((biR.biWidth * biR.biBitCount) + 31) & ~31) / 8) * abs(biR.biHeight);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    // int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {

        // Adding extra variable
        //
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // TODO: Add code here:


            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
