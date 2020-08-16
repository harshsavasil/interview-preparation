# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getHeight(self, root: TreeNode) -> int:
        if root is None:
            return -1
        if root.left is None and root.right is None:  # leaf node
            return 0
        return max(self.getHeight(root.left), self.getHeight(root.right)) + 1


root = TreeNode(3)
root.left = TreeNode(5)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)
root.right = TreeNode(1)
root.right.left = TreeNode(0)
root.right.right = TreeNode(8)


solution = Solution()
assert solution.getHeight(root) == 3, "test case 1 failed"
assert solution.getHeight(root.right) == 1, "test case 1 failed"
assert solution.getHeight(root.left) == 2, "test case 1 failed"
