from typing import List


class Solution:
    def __init__(self):
        self._ans = []
        self._total = 0

    def generate_permutations(self, index, nums):
        if index == self._total:
            self._ans.append(nums.copy())
            return
        for i in range(index, self._total):
            nums[index], nums[i] = nums[i], nums[index]
            self.generate_permutations(index + 1, nums)
            nums[index], nums[i] = nums[i], nums[index]

    def permute(self, numbers: List[int]) -> List[List[int]]:
        self._total = len(numbers)
        self.generate_permutations(0, numbers)
        return self._ans


solution = Solution()
print(solution.permute([1, 2, 3, 4]))
