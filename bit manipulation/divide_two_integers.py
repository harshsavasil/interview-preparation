class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        quotient = 0
        sign = -1 if((dividend < 0) ^ (divisor < 0)) else 1
        divisor = abs(divisor)
        dividend = abs(dividend)
        temp = 0
        for i in range(31, -1, -1): 
            if (temp + (divisor << i) <= dividend): 
                temp += divisor << i
                quotient |= 1 << i
        if sign > 0 and quotient >= (1 << 31):
            return (1 << 31) - 1
        if sign < 0 and quotient > (1 << 31):
            return -(1 << 31)
        return sign * quotient


solution = Solution()
assert solution.divide(100, 3) == 33, "Test case failed"
assert solution.divide(-2147483648, -1) == 2147483647, "Test case failed"
assert solution.divide(-2147483648, 1) == -2147483648, "Test case failed"
