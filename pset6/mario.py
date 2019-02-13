# Python version of mario.c
# To run: python3 mario.py

from cs50 import get_int

# User determines height
while True:
    height = get_int("What is the height of the pyramid? ")

    # Height must be no greater than 23
    if height >= 0 and height < 24:
        break

# Print a pyramid of # if i(integer) is between 1 and 23
for i in range(height):
        # Aligns the pyramid to the right
        print(" " * (height - i - 1), end="")
        # Top stack is always ##
        print("#" * (i + 2))
