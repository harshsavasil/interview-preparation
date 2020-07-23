class Solution:
    def mySqrt(self, x: int) -> int:
        sqrt = 0
        temp = 0
        for i in range(31, -1, -1): 
            if (temp + (1 << i)) * (temp + (1 << i)) <= x: 
                temp += (1 << i)
                sqrt |= 1 << i
        return sqrt


solution = Solution()
# assert solution.mySqrt(1) == 1, "Test case 1 failed"
# assert solution.mySqrt(0) == 0, "Test case 2 failed"
assert solution.mySqrt(8) == 2, "Test case 2 failed"