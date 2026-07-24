# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
# We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
# You must solve this problem without using the library's sort function.

# Example 1:
# Input: nums = [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]

# Example 2:
# Input: nums = [2,0,1]
# Output: [0,1,2]

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        arr0 = []
        arr1 = []
        arr2 = []
        for i in nums:
            if i == 0:
                arr0.append(i)
            elif i == 1:
                arr1.append(i)
            elif i == 2:
                arr2.append(i)
        nums[ : ] = arr0 + arr1 + arr2
        return nums


