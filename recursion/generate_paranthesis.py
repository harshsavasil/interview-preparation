import collections
from typing import List


class Solution:
    def generateParenthesisUsingBFS(self, n: int) -> List[str]:
        ans = []
        # For element in queue, it means (pre-string, left, right)
        queue = collections.deque([('', n, n)])
        while queue:
            pre, left, right = queue.popleft()
            if right == 0:
                ans.append(pre)
            if left:
                queue.append((pre + '(', left - 1, right))
            if right > left:
                queue.append((pre + ')', left, right - 1))
        return ans

    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def helper(openB, closeB, brackets):
            if closeB == 0:
                ans.append(brackets)
            if openB > 0:  # add open bracket
                helper(openB - 1, closeB, brackets + "(")
            if closeB > openB:
                helper(openB, closeB - 1, brackets + ")")
        helper(n, n, "")
        return ans


solution = Solution()
print(solution.generateParenthesis(3))
print(solution.generateParenthesisUsingBFS(3))
