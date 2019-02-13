# Implement a program that encrypts messages using Caesar’s cipher
# Implementation: python3 caesar.py 5

import sys
from cs50 import get_string

def main():
    # Cypher needs only one argument

    if len(sys.argv) == 1:
        print("Please add one argument.")

    # Change the string into an int
    key = int(sys.argv[1])

    # Ask the user for a string
    plain = get_string("Enter a string: ")

    # Print out the cypher
    print("ciphertext: ", end="")

    # char(c) will change
    for c in plain:
        # Uppercase letter
        if c.isupper():
            print("{}".format(chr((ord(c) - ord("A") + key) % 26 + ord("A"))), end="")

        # Lowercase letter
        elif c.islower():
            print("{}".format(chr((ord(c) - ord("a") + key) % 26 + ord("a"))), end="")

        # All others
        else:
            print("{}".format(c), end="")


if __name__ == "__main__":
    main()