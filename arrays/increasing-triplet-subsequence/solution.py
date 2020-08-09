from typing import List


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        left = float('inf')
        mid = float('inf')
        index = 0
        while index < n:
            if nums[index] < left:
                left = nums[index]
            elif nums[index] > mid:
                return True
            elif nums[index] > left:  # for strictly increasing
                mid = nums[index]
            index += 1
        return False


solution = Solution()
assert solution.increasingTriplet(
    [5, 4, 2, 1, 0]) == False, "Test case 1 failed"
assert solution.increasingTriplet(
    [1, 0, 2, 1, 3]) == True, "Test case 1 failed"
