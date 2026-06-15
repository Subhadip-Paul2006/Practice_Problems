# Problem Statement:
# Given an array arr of N positive integers, find the smallest divisor x of N such that x > 1. Partition the array into consecutive groups of size x. Sort each group individually in descending order and concatenate all groups in their original order. Return the resulting array.

# Input Format :
# 01. The first line contains an integer N, representing the number of elements in the array.
# 02. The next N lines each contain an integer arr[i], representing the elements of the array.

# Output Format :
# Print the modified array after:
# 01. Finding the smallest divisor x > 1 of N.
# 02. Dividing the array into groups of size x.
# 03. Sorting each group in descending order.
# Print one integer per line.

# Constraints :
# 2 ≤ N ≤ 10^5
# 1 ≤ arr[i] ≤ 10^9

# Sample Input: 
# 6 2 6 3 7 2 7
# Sample Output:
# 6 2 7 3 7 2



# !/bin/python3

def GroupingArray(arr):
    n = len(arr)

    # Find smallest divisor > 1
    x = 2
    while n % x != 0:
        x += 1

    result = []

    # Sort each group in descending order
    for i in range(0, n, x):
        group = sorted(arr[i:i + x], reverse=True)
        result.extend(group)

    return result


if __name__ == '__main__':
    array_count = int(input().strip())

    arr = []

    for _ in range(array_count):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = GroupingArray(arr)

    print('\n'.join(map(str, result)))