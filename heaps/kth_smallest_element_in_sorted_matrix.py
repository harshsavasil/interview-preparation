# TC - O(min(k, n) + klog(min(k, n)))
from heapq import heappush, heappop
from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        minHeap = []
        n = len(matrix)
        m = 0 if n == 0 else len(matrix[0])
        for row in range(min(k, len(matrix))):
            heappush(minHeap, (matrix[row][0], row, 0))
        count = 0
        while minHeap:
            current, row, column = heappop(minHeap)
            count += 1
            if count == k:
                return current
            if column + 1 < m:
                heappush(minHeap, (matrix[row][column + 1], row, column + 1))
        return matrix[0][0]


solution = Solution()
assert solution.kthSmallest([
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [25, 29, 37, 48],
    [32, 33, 39, 50]
], 7) == 30, "Test case failed"
