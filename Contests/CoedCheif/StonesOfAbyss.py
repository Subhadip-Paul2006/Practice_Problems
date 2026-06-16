# Stones of the Abyss Alice and Bob are playing a game with a single pile containing  N stones. They play alternating turns, and Alice always makes the first move.

# The rules of the game are as follows :
# On her turn, Alice can remove any odd number of stones from the pile.
# On his turn, Bob can remove any positive even number of stones from the pile.
# A player loses if they cannot make a valid move on their turn (i.e., there are not enough stones left to pick a valid number). Assuming both Alice and Bob play optimally to win, determine who will win the game.

# Function Declaration
# Function Name :
# stoneAbbys – This function determines the winner of the game based on the initial number of stones in the pile, assuming optimal play from both players.
# Parameters
# N : An integer representing the initial number of stones in the pile.
# Return Value
# Returns a string: The name of the winning player (e.g., "Alice" or "Bob").
# Constraints:
# 0 ≤ N ≤ 10^9
 
# The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.

# Input Format
# An integer N — the initial number of stones in the pile.
# Output Format
# Print Alice if Alice wins the game, or Bob if Bob wins.


def stoneAbbys(N: int) -> str:
    """Return the winner ('Alice' or 'Bob') for a pile of N stones.

    Alice removes any odd positive number on her turns; Bob removes any
    positive even number on his turns. A player who cannot move loses.

    Observations:
    - If N == 0, Alice cannot move and loses -> Bob wins.
    - For N % 4 == 2, Bob wins with optimal play; otherwise Alice wins.
    """
    if N == 0 or N % 4 == 2:
        return "Bob"
    return "Alice"


if __name__ == "__main__":
    import sys

    data = []
    try:
        data = list(map(int, input().strip().split()))
    except Exception:
        pass

    if len(data) == 0:
        data = list(map(int, sys.stdin.read().strip().split()))

    if not data:
        print("Usage: provide integer N, e.g. '7'")
    else:
        N = data[0]
        print(stoneAbbys(N))