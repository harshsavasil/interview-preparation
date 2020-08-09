# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getPath(self, root, node, path):
        if root is None:
            return False
        path += [root]
        if root.val == node.val:
            return True
        if root.left:
            if self.getPath(root.left, node, path):
                return True  # no need to search further
            path.pop()  # pop if not found in left subTree
        if root.right:
            if self.getPath(root.right, node, path):
                return True
            path.pop()
        return False

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        path = []
        self.getPath(root, p, path)
        pathP = path.copy()
        # print([node.val for node in pathP])
        path = []
        self.getPath(root, q, path)
        pathQ = path.copy()
        # print([node.val for node in pathQ])
        for node in reversed(pathP):
            if node in pathQ:
                return node


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
output = solution.lowestCommonAncestor(root, TreeNode(5), TreeNode(4))
assert output.val == 5, "test case 1 failed"
output = solution.lowestCommonAncestor(root, TreeNode(3), TreeNode(4))
assert output.val == 3, "test case 2 failed"
output = solution.lowestCommonAncestor(root, TreeNode(1), TreeNode(4))
assert output.val == 3, "test case 3 failed"
output = solution.lowestCommonAncestor(root, TreeNode(6), TreeNode(7))
assert output.val == 5, "test case 4 failed"
