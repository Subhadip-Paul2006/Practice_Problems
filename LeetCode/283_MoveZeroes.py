# Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
# Note that you must do this in-place without making a copy of the array.

# Example:
# Input: nums = [0,1,0,3,12]
# Output: [1,3,12,0,0]

def moveZeroes(nums):
    temp = []
    flag = 0
    for i in nums:
        if i > 0 or i < 0:
            temp.append(i)
        elif i == 0:
            flag += 1
        
    for i in range(flag):
        temp.append(0)
    nums[ : ] = temp
    print(nums)

arr01 = [0, 1, 0, 3, 12]
moveZeroes( arr01)
