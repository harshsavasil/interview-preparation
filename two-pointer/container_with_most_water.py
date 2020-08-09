# Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
# Input: [1,8,6,2,5,4,8,3,7]
# Output: 49
# Note: You may not slant the container and n is at least 2.

from typing import List


class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights)
        left = 0
        right = n - 1
        height = None
        maxWater = 0
        while left < right:
            if heights[left] <= heights[right]:
                height = heights[left]
                left += 1
            else:
                height = heights[right]
                right -= 1
            maxWater = max(maxWater, height * (right - left + 1))
        return maxWater


solution = Solution()
assert solution.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
assert solution.maxArea([]) == 0
