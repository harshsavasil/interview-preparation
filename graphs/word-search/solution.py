from typing import List


class Solution:
    def __init__(self):
        self._rows = None
        self._columns = None
        self._visited = []
        self._word = None
        self._board = []

    def getNeighbours(self, row, column):
        neighbours = []
        for i in [1, -1]:
            if 0 <= row + i < self._rows:
                neighbours.append((row + i, column))
            if 0 <= column + i < self._columns:
                neighbours.append((row, column + i))
        return neighbours

    def dfs(self, row, column, index):
        if index == len(self._word) - 1:
            return True
        neighbors = self.getNeighbours(row, column)
        found = False
        for neighbor in neighbors:
            if not self._visited[neighbor[0]][neighbor[1]] and self._board[neighbor[0]][neighbor[1]] == self._word[index + 1]:
                self._visited[neighbor[0]][neighbor[1]] = True
                found = found or self.dfs(neighbor[0], neighbor[1], index + 1)
                if found:
                    return True
                self._visited[neighbor[0]][neighbor[1]] = False
        return found

    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(word) == 0:
            return True
        self._rows = len(board)
        self._columns = 0 if self._rows == 0 else len(board[0])
        self._visited = [[False for _ in range(
            self._columns)] for _ in range(self._rows)]
        self._board = board
        self._word = word
        for row in range(self._rows):
            for column in range(self._columns):
                if word[0] == board[row][column]:
                    self._visited[row][column] = True
                    found = self.dfs(row, column, 0)
                    if found:
                        return found
                    self._visited[row][column] = False
        return False


solution = Solution()
print(solution.exist([["A", "B", "C", "E"], [
      "S", "F", "C", "S"], ["A", "D", "E", "E"]], ""))
