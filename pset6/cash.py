# Implement a program that calculates the minimum number of coins required to give the user change

# Using numbers with decimals: Need float
from cs50 import get_float

coins = 0

# Ask the user for the amount of change (make sure it's a positive number)
while True:
    change = get_float("How much change do you need? ")
    if change > 0:
        break

# Change value gets changed into an integer without decimals
change = round(int(change * 100))

# Diving the previous variable change to see how many coins the user gets
# ! Start with the largest coin first!

coins = change // 25
change %= 25

coins += change // 10
change %= 10

coins += change // 5
change %= 5

coins += change // 1
# Get the amount of coins
print(coins)