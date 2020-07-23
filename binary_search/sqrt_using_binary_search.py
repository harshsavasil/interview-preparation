class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        low = 0
        high = x // 2
        ans = 0
        while low <= high:
            mid = low + (high - low) // 2
            if mid * mid <= x:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return ans

solution = Solution()
assert solution.mySqrt(1) == 1, "Test case 1 failed"
assert solution.mySqrt(0) == 0, "Test case 2 failed"
assert solution.mySqrt(8) == 2, "Test case 2 failed"