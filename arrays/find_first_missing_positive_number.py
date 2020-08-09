from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        index = 0
        while index < n:
            if 1 <= nums[index] <= n and index != nums[index] - 1:
                temp = nums[index]
                nums[index] = nums[temp - 1]
                nums[temp - 1] = temp
            else:
                index += 1
        for index in range(n):
            if index + 1 != nums[index]:
                return index + 1
        return n + 1


solution = Solution()
output = solution.firstMissingPositive([3, 4, -1, 1])
print(output)
