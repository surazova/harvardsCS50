# Implement a program that encrypts messages using Caesar’s cipher

import sys
from cs50 import get_string

# Cypher needs only one argument

if len(sys.argv) == 1:
    print("Please add one argument.")

# Change the string into an int
key = int(sys.argv[1])

# Ask the user for a string
plain = get_string("Enter a string: ")

# Print out the cypher
print("ciphertext: ", end="")

for char in plain:
    # Uppercase letter
    if char.isupper(:
        print("{}".format(chr((ord(char) - ord("A") + key) % 26 + ord("A"))), end="")

    # Lowercase letter