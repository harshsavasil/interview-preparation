# TC - O(min(k, n) + klog(min(k, n)))
from typing import List


class Solution:
    def getCount(self, matrix, element):
        """
        Start from the last element of first column and start reducing search space
        by comparing the values. This function returns the count of elements less
        than or equal to the element.
        """
        n = len(matrix)
        m = len(matrix[0])
        row = n - 1
        column = 0
        count = 0
        smaller, larger = matrix[0][0], matrix[n - 1][n - 1]
        while row >= 0 and column < m:
            if matrix[row][column] <= element:
                smaller = max(smaller, matrix[row][column])
                count += row + 1
                column += 1
            else:
                larger = min(larger, matrix[row][column])
                row -= 1
        return count, smaller, larger

    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        m = 0 if len(matrix) == 0 else len(matrix[0])
        if n == 0:
            return 0
        low = matrix[0][0]
        high = matrix[n - 1][m - 1]
        while low < high:
            mid = low + (high - low) // 2
            count, smaller, larger = self.getCount(matrix, mid)
            if count == k:
                return smaller
            elif count < k:
                low = larger
            else:
                high = smaller
        return low


solution = Solution()
assert solution.kthSmallest([
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [25, 29, 37, 48],
    [32, 33, 39, 50]
], 1) == 10, "Test case failed"

assert solution.kthSmallest([[1, 2], [1, 3]], 1) == 1, "Test case failed"
assert solution.kthSmallest([[1, 2], [1, 3]], 2) == 1, "Test case failed"
assert solution.kthSmallest([[1, 2], [1, 3]], 3) == 2, "Test case failed"
assert solution.kthSmallest([[1, 2], [1, 3]], 4) == 3, "Test case failed"
assert solution.kthSmallest(
    [[1, 3, 5], [6, 7, 12], [11, 14, 14]], 4) == 6, "Test case failed"
