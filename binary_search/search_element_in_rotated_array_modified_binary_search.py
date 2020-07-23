from typing import List

# leetcode accepted solution
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] <= nums[high]:
                if target > nums[mid] and target <= nums[high]: # right part is sorted array
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                if target >= nums[low] and target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
        return -1

solution = Solution()
print(solution.search([4, 5, 6, 6, 0, 1, 2], 3))
print(solution.search([4, 5, 6, 6, 0, 1, 2], 2))
print(solution.search([4, 5, 6, 6, 0, 1, 2], 6))