# Alice is playing a game on her PC. Her current score is a. To win the game, she needs a score of at least w. Alice has found a bonus item that instantly increases her score by b points. Determine whether Alice can win the game after collecting the bonus item.

# Function Name : 
# canWin – This function checks whether Alice can win the game after collecting the bonus item.

# Parameters
# a : An integer representing Alice's current score.
# b : An integer representing the bonus points collected.
# w : An integer representing the target score required to win.

# Return Value :
# Returns a boolean: True if Alice can win the game, and false otherwise.

# Input Format :
# The function takes three integers as input: a, b, and w.
# Output Format :
# The function returns a boolean value: True if Alice can win the game, and False otherwise.
# Constants :
# 0 ≤ a ≤ 100
# 0 ≤ b ≤ 100
# 1 ≤ w ≤ 100

# Sample Input 1 :
# 15 10 20 
# Sample Output 1 :
# True

def canWin(a: int, b: int, w: int) -> bool:
    return a + b >= w

