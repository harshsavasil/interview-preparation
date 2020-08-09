from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        triplets = []
        index = 0
        while index < n - 2:
            if nums[index] <= 0:
                left = index + 1
                right = n - 1
                while left < right:
                    print(index, left, right)
                    if nums[index] + nums[left] + nums[right] == 0:
                        triplets.append((nums[index], nums[left], nums[right]))
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        right -= 1
                    elif nums[index] + nums[left] + nums[right] > 0:
                        right -= 1
                    else:
                        left += 1
            while index < n - 2 and nums[index] == nums[index + 1]:
                index += 1
            index += 1
        return triplets


solution = Solution()
output = solution.threeSum([-1, 0, 1, 2, -1, -4])
assert output == [(-1, -1, 2), (-1, 0, 1)], "test case failed"
