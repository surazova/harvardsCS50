# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A disease of the lungs resulting from the inhalation of very fine silicate or quartz dust' 'Pneumonoultramicroscopicsilicavolcanoconiosis is a form of the illness pneumoconiosis, caused by the inhalation of a fine silica dust found in most volcanoes.'

## According to its man page, what does `getrusage` do?

Get resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Not using before and after will make the program slower and will take up a lot of memory.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
The challenge is to implement load, check, size, and unload as efficiently as possible, in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. To be sure, it’s not obvious what it even means to be minimized, inasmuch as these benchmarks will certainly vary as you feed speller different values for dictionary and for text. But therein lies the challenge, if not the fun, of this problem set. This problem set is your chance to design. Although we invite you to minimize space, your ultimate enemy is time.

Within the default dictionary are 143,091 words, all of which must be loaded into memory! In fact, take a peek at that file to get a sense of its structure and size. Notice that every word in that file appears in lowercase. From top to bottom, the file is sorted lexicographically, with only one word per line (each of which ends with \n). No word is longer than 45 characters, and no word appears more than once.

So that you can test your implementation of speller, we’ve also provided you with a whole bunch of texts, among them the script from Austin Powers: International Man of Mystery, a sound bite from Ralph Wiggum, three million bytes from Tolstoy, some excerpts from Machiavelli and Shakespeare, the entirety of the King James V Bible, and more.

