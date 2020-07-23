from typing import List

class Solution:
    def nextGreaterElement(self, array: List[int], x: int) -> int:
        n = len(array)
        low = 0
        high = n - 1
        ans = None
        while low <= high:
            mid = low + (high - low) // 2
            if x == array[mid]:
                return -1 # to handle the case when the number already exists in lis
            elif x > array[mid]:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1
        return ans
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        lis = []
        for num in nums:
            if len(lis) == 0:
                lis.append(num)
            else:
                if lis[-1] < num:
                    lis.append(num)
                else:
                    # find the index of next greater element
                    index = self.nextGreaterElement(lis, num)
                    if index != -1: # don't swap if the no. already exists
                        lis[index] = num
        return len(lis)


solution = Solution()
assert solution.lengthOfLIS([4,10,4,3,8,9]) == 3, "Test case 1 failed"