# Problem Statement :
# You are given an array A of N positive integers representing the heights of bars in a histogram. Each bar has a width of 1 unit. Your task is to find the area of the largest rectangle that can be formed within the bounds of the histogram.
# A1, A2, A3, ..., AN. 
# A represents a histogram which means the height of the i-th bar will be Ai units and the width of each bar is 1 unit.
# Find the area of the largest rectangle in the histogram.

# Function Declaration
# Function Name :
# largestRectangleArea – This function calculates the maximum rectangular area possible within the given histogram.

# Parameters :
# N : An integer representing the number of bars in the histogram.
# A : An array of integers representing the heights of the histogram bars.
# Return Value
# Returns an integer: the area of the largest rectangle that can be formed in the histogram.

# Constraints:
# 1 ≤ T ≤ 10
# 1 ≤ N ≤ 10^5
# 0 ≤ Ai ≤ 10^9 
# The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.

# Input Format
# 01. The first line of input will contain a single integer T, denoting the number of test cases. 
# 02. The first line of each test case contains an integer N - the length of the array A
# 03. The second line of each test case contains  N space-separated integers A1, A2, ..., AN - the heights of the histogram bars.

# Output Format
# For each test case, output on a new line the area of the largest rectangle in the histogram.

# Subtasks
# Subtask 1 (30 points): 1 ≤ N ≤ 1000
# Subtask 2 (70 points): No further constraints.

# Sample Input 1 :
# 3
# 4
# 2 6 8 4
# 4
# 5 10 5 2
# 2
# 5 5
# Sample Output 1 :
# 12    
# 15
# 10

def largestRectangleArea(N: int, A: list[int]) -> int:
    stack = []
    max_area = 0
    
    for i in range(N + 1):
        currentHeight = 0 if i == N else A[i]
        while stack and A[stack[-1]] > currentHeight:
            h = A[stack.pop()]
            if stack:
                w = i - stack[-1] - 1
            else :
                w = i
            max_area = max(max_area, h * w)
        stack.append(i)
    return max_area

if __name__ == "__main__":
    import sys

    data = []
    try:
        data = list(map(int, input().strip().split()))
    except Exception:
        pass

    if len(data) < 1:
        data = list(map(int, sys.stdin.read().strip().split()))

    if len(data) >= 2:
        T = data[0]
        index = 1
        for _ in range(T):
            N = data[index]
            index += 1
            A = data[index:index + N]
            index += N
            print(largestRectangleArea(N, A))
    else:
        print("Usage: provide an integer T followed by T test cases, each with an integer N and N integers for the histogram heights.")

