# Given an array of integers arr[], the task is to find the first equilibrium point in the array.
# The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

# Examples:
# Input: arr[] = [1, 2, 0, 3]
# Output: 2 

# Input: arr[] = [1, 1, 1, 1]
# Output: -1

# Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
# Output: 3

def point(arr):
    total = sum(arr)
    left = 0
    right = 0
    for i in range(len(arr)):
        right = total - left - arr[i]
        if left == right:
            return i
        left += arr[i]
    return -1

arr = [1, 2, 0, 3]
print(point(arr))