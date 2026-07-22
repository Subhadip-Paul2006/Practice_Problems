# Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

# Example 1:
# Input: nums = [3,0,1]
# Output: 2

# Example 2:
# Input: nums = [0,1]
# Output: 2


def missingNumber(nums):
    n = len(nums)
    TestArr = []
    for i in range(n+1):
        TestArr.append(i)
    for i in TestArr:
        if i not in nums:
            return i

arr01 = []
n = int(input("Enter the number of elements in the array: "))
for i in range(n):
    arr01.append(int(input()))
print(missingNumber(arr01))