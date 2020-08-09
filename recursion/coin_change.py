"""
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

Note: You may assume that you have an infinite number of each kind of coin.
Solution 1 using dp O(n^2)
Solution 2 using dfs or bfs with pruning
"""

from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        self.ans = float('inf')

        # Start searching from the biggest coin
        coins.sort(reverse=True)
        self.dfs(coins, amount, 0)
        return -1 if self.ans == float('inf') else self.ans

    def dfs(self, coins, amount, prev_count):
        """
        Recursive DFS function to seach valid coins combination.
        First is to use greedy method find out a potential-best solution.
        Then start to search the second biggest coin with pruning when the coins number >= the potential-best solution.

        Args:
            coins: coins list from which we pick coins into combination
            amount: target amount 
            prev_count: number of coins picked before this round

        """
        # Set up stop condtion
        if len(coins) == 0:
            return

        if amount % coins[0] == 0:
            # Update potential answer
            self.ans = min(self.ans, prev_count + amount // coins[0])
        else:
            for k in range(amount // coins[0], -1, -1):
                # Set up pruning condtion
                if prev_count + k >= self.ans:
                    break
                self.dfs(coins[1:], amount - k * coins[0], prev_count + k)


solution = Solution()
assert solution.coinChange([1, 2, 5], 11) == 3, "Test case 1 failed"
assert solution.coinChange([1, 2, 5], 13) == 4, "Test case 2 failed"
