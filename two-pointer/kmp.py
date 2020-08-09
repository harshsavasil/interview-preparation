from typing import List


class Solution:
    def generate_lps(self, needle: str) -> List[int]:
        n = len(needle)
        lps = [0] * n
        i = 1
        j = 0
        while i < n:
            if needle[i] == needle[j]:
                lps[i] = j + 1
                i += 1
                j += 1
            else:
                if j == 0:
                    lps[i] = 0
                    i += 1
                else:
                    j = lps[j - 1]
        return lps

    def strStr(self, haystack: str, needle: str) -> int:
        if needle:
            h = len(haystack)
            n = len(needle)
            lps = self.generate_lps(needle)
            hp = 0  # haystack pointer
            np = 0  # needle pointer
            while hp < h:
                if haystack[hp] == needle[np]:
                    hp += 1
                    np += 1
                else:
                    if np == 0:
                        hp += 1
                    else:
                        np = lps[np - 1]
                if np == n:
                    return hp - np
            return -1
        return 0


solution = Solution()
output = solution.strStr("mississippi", "issip")
assert output == 4, "test case failed"
