# Problem Statement :
# You are given an array arr of N positive integers. In each move, you can pick two different numbers from the array where their absolute difference is at most one, and remove the smaller one. If two numbers are the same, you can remove either. Your goal is to determine if you can reduce the array to exactly one number using these moves.

# Function Declaration
# Function Name :
# canReduce – This function determines whether the array can be reduced to just one number based on the given rules.

# Parameters
# N : An integer representing the size of the array. arr : An array of integers representing the given sequence.

# Return Value
# Returns a boolean : true if the array can be reduced to a single number, and  false otherwise.

# Constraints :
# 1 ≤ N ≤ 10^4
# 1 ≤ arr[i] ≤ 10^4
 

# The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.

# Input Format
# The first line contains an integer N representing the size of  arr.
# Next lines contain N integers that are present in arr.
# Output Format
# Output "YES" if it's possible to reduce the array to one element, otherwise "NO".

# Sample Input 1 :
# 4
# 4 1 3 2
# Sample Output 1 :
# YES


def canReduce(N: int, arr: list[int]) -> bool:
    arr.sort()
    for i in range (1, N):
        if arr[i] - arr[i - 1] > 1:
            return False
    return True

if __name__ == "__main__":
    import sys

    data = []
    try:
        data = list(map(int, input().strip().split()))
    except Exception:
        pass

    if len(data) < 1:
        data = list(map(int, sys.stdin.read().strip().split()))

    if len(data) >= 1:
        N = data[0]
        arr = data[1:N + 1]
        print("YES" if canReduce(N, arr) else "NO")
    else:
        print("Usage: provide an integer N followed by N integers, e.g. '4 4 1 3 2'")
