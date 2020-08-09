from typing import List


class Solution:
    def trap(self, heights: List[int]) -> int:
        n = len(heights)
        if n == 0:
            return 0
        left, right = 0, n - 1
        waterTrapped = 0
        leftMax, rightMax = heights[left], heights[right]
        while left <= right:
            if heights[left] <= heights[right]:
                waterTrapped += (0 if leftMax <
                                 heights[left] else leftMax - heights[left])
                left += 1
                if left < n:
                    leftMax = max(leftMax, heights[left])
            else:
                waterTrapped += (0 if rightMax <
                                 heights[right] else rightMax - heights[right])
                right -= 1
                if right >= 0:
                    rightMax = max(rightMax, heights[right])

        return waterTrapped


solution = Solution()
assert solution.trap(
    [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
) == 6, "test case 1 failed"
