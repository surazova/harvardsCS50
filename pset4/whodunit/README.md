# Questions

## What's `stdint.h`?

A header file that declares sets of integer types with a specified width and also defines corresponding macros.
These macros specify limits of integer types that are defined in other standard headers. The width is the number of bits used to store its value in a pure binary system.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Shows that you want to use the data in a specific way.
uint8_t: an unsigned int of 8 bits
uint32_t: an unsigned long long
uint16_t: an unsigned 16 bit int
int32_t: a signed long long

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1
DWORD: 4 (32 bits)
LONG: 4 (32 bits)
WORD: 2 (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes specify the file is a bitmap with the words "BM", or the hex code 0x4D42

## What's the difference between `bfSize` and `biSize`?

bfSize: the size in bytes, of the bitmap file
biSize: the whole image size

## What does it mean if `biHeight` is negative?

if biHeight is positive, the bitmap is a bottom-up DIB and its origins is the lower-left corner. If biHeight is negative, the bitmap is a top-down DIB and its
origins is the upper-left corner. Then, it's compression must either be BI_RGB or BI_BITFIELDS.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

TODO

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

TODO

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

fseek is a function used to move the file position to a desired location within the file. It takes the form:
fssek(file_ptr,offset,position) and acts as a pointer to the file concerned, offset is a number or variable of types long and position is an integer number.

## What is `SEEK_CUR`?

It specifies that offset is a count of characters from the current file position. The count may be positive or negative.

## Whodunit?

TODO
