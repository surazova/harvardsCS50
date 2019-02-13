# Python version of mario.c
# To run: python3 mario.py

from cs50 import get_int

# User determines height
while True:
    height = get_int("What is the height of the pyramid? ")
    if height >= 0 and height < 24:
        break

# Print a pyramid of #
for i in range(height):
        print(" " * (height - i - 1), end="")
        print("#" * (i + 2))
