from collections import Counter


class Solution:
    def isValid(self, count):
        for key in count:
            if count[key] > 0:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:
        count = Counter(t)
        foundIndices = []
        start = 0
        ans = ""
        for index, character in enumerate(s):
            if character in count:
                foundIndices.append(index)
                count[s[index]] -= 1
                while self.isValid(count):
                    count[s[foundIndices[start]]] += 1
                    if not ans or len(ans) > foundIndices[-1] - foundIndices[start] + 1:
                        ans = s[foundIndices[start]: foundIndices[-1] + 1]
                    start += 1
        return ans


solution = Solution()
assert solution.minWindow("ADOBECODEBANC", "ABC") == 'BANC'
assert solution.minWindow("ab", "b") == 'b'
assert solution.minWindow("cabwefgewcwaefgcf", "cae") == 'cwae'
