# Stones of the Abyss
# Alice and Bob are playing a game with a single pile containing 
# N
# N stones. They play alternating turns, and Alice always makes the first move.

# The rules of the game are as follows:

# On her turn, Alice can remove any odd number of stones from the pile.
# On his turn, Bob can remove any positive even number of stones from the pile.
# A player loses if they cannot make a valid move on their turn (i.e., there are not enough stones left to pick a valid number). Assuming both Alice and Bob play optimally to win, determine who will win the game.

# Function Declaration
# Function Name
# s
# t
# o
# n
# e
# A
# b
# b
# y
# s
# stoneAbbys – This function determines the winner of the game based on the initial number of stones in the pile, assuming optimal play from both players.

# Parameters
# N
# N : An integer representing the initial number of stones in the pile.

# Return Value
# Returns a string: The name of the winning player (e.g., "Alice" or "Bob").

# Constraints:
# 0
# ≤
# N
# ≤
# 10
# 9
# 0≤N≤10 
# 9
 

# The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.

# Input Format
# An integer 
# N
# N — the initial number of stones in the pile.

# Output Format
# Print Alice if Alice wins the game, or Bob if Bob wins.


def stoneAbbys(N: int) -> str:
    if N == 0 or N % 4 == 2:
        return "Bob"
    return "Alice"