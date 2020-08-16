# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getLeafNodeSum(self, root: TreeNode) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return root.val
        total = 0
        if root.left:
            total += self.getLeafNodeSum(root.left)
        if root.right:
            total += self.getLeafNodeSum(root.right)
        return total


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
output = solution.getLeafNodeSum(root)
assert output == 25, "test case 1 failed"
