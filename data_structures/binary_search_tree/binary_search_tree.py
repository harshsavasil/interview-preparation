from queue import Queue 
import sys

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

class _BinarySearchTreeInterator:
    def __init__ (self, root, size):
        self._theKeys = [None] * size
        self._curItem = 0
        self._bstPostOrderTraversal(root)
        self._curItem = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._curItem < len(self._theKeys):
            key = self._theKeys[self._curItem]
            self._curItem += 1
            return key
        else:
            raise StopIteration
    
    def _bstInorderTraversal(self, subtree):
        """
        Performs an inorder traversal used to build the array of keys.
        """
        if subtree is not None:
            self._bstInorderTraversal(subtree.left)
            self._theKeys[self._curItem] = subtree.key
            self._curItem += 1
            self._bstInorderTraversal(subtree.right)
    
    def _bstPreOrderTraversal(self, subtree):
        """
        Performs an inorder traversal used to build the array of keys.
        """
        if subtree is not None:
            self._theKeys[self._curItem] = subtree.key
            self._curItem += 1
            self._bstPreOrderTraversal(subtree.left)
            self._bstPreOrderTraversal(subtree.right)
    
    def _bstPostOrderTraversal(self, subtree):
        """
        Performs an inorder traversal used to build the array of keys.
        """
        if subtree is not None:
            self._bstPostOrderTraversal(subtree.left)
            self._bstPostOrderTraversal(subtree.right)
            self._theKeys[self._curItem] = subtree.key
            self._curItem += 1
    
    def _bstLevelOrderTraversal(self, subtree):
        """
        Performs a level order traversal used to build the array of keys.
        """
        if subtree is not None:
            bfsQueue = Queue(maxsize = len(self._theKeys))
            bfsQueue.put(subtree)
            while not bfsQueue.empty():
                current = bfsQueue.get()
                print(current.key)
                self._theKeys[self._curItem] = current.key
                self._curItem += 1
                if current.left is not None:
                    bfsQueue.put(current.left)
                if current.right is not None:
                    bfsQueue.put(current.right)


class BinarySearchTree:
    """
        Binary Search Tree Implementation
    """
    def __init__(self):
        self._root = None
        self._size = 0
    
    def __len__(self):
        return self._size

    def __iter__(self):
        return _BinarySearchTreeInterator(self._root, self._size)

    def __contains__(self, key):
        return self._bstSearch(self._root, key) is not None

    def valueOf(self, key):
        node = self._bstSearch(self._root, key)
        assert node is not None, "Invalid map key."
        return node.value

    def _bstSearch(self, subtree, target):
        if subtree is None:                                             # base case
            return None                                                         
        if subtree.key == target:
            return subtree
        elif subtree.key > target:                                      # search in left subtree
            return self._bstSearch(subtree.left, target)
        return self._bstSearch(subtree.right, target)                   # search in right subtree

    def _bstMinimum(self, subtree):
        if subtree is None:
            return None
        elif subtree.left is None:
            return subtree
        return self._bstMinimum(subtree.left)
    
    def _bstMaximum(self, subtree):
        if subtree is None:
            return None
        elif subtree.right is None:
            return subtree
        return self._bstMinimum(subtree.right)

    def add(self, key, value):
        node = self._bstSearch(self._root, key)                        # if key already exists, update the value
        if node:
            node.value = value
        else:
            self._root = self._bstInsert(self._root, key, value)       # else create a new node in bst
            self._size += 1
            return True

    def _bstInsert(self, subtree, key, value):
        if subtree is None:
            subtree = Node(key, value)
            return subtree
        if key < subtree.key:
            subtree.left = self._bstInsert(subtree.left, key, value)
        else:
            subtree.right = self._bstInsert(subtree.right, key, value)
        return subtree

    def remove(self, key):
        assert key in self, "Invalid Map key."
        self._root = self._bstRemove(self._root, key)
        self._size -= 1

    def _bstRemove(self, subtree, target):
        if subtree is None:
            return subtree
        if target < subtree.key:
            subtree.left = self._bstRemove(subtree.left, target)
            return subtree
        elif target > subtree.key:
            subtree.right = self._bstRemove(subtree.right, target)
            return subtree
        else:
            if subtree.left is None and subtree.right is None:                          # for leaf nodes. Just delete the link
                return None
            elif subtree.left is None or subtree.right is None:
                if subtree.left:
                    return subtree.left
                return subtree.right
            else:
                # for nodes having both children, replace node with min in right subtree and delete the value in right subtree
                successor = self._bstMinimum(subtree.right)
                subtree.key = successor.key
                subtree.value = successor.value
                subtree.right = self._bstRemove(subtree.right, successor.key)
                return subtree
    
    def getTreeHeight(self):
        return self._getHeightOfSubtree(self._root)
    
    def _getHeightOfSubtree(self, subtree):
        if subtree is None:
            return -1
        if subtree.left is None and subtree.right is None:
            return 0
        return 1 + max(self._getHeightOfSubtree(subtree.left), self._getHeightOfSubtree(subtree.right))
    
    def isBinarySearchTree(self):
        return self._isBinarySearchTreeHelper(self._root, -sys.maxsize, sys.maxsize)
    
    def _isBinarySearchTreeHelper(self, subtree, minV, maxV):
        if subtree is None:
            return True
        if subtree.key < minV or subtree.key >= maxV:
            return False
        return self._isBinarySearchTreeHelper(subtree.left, minV, subtree.key) and self._isBinarySearchTreeHelper(subtree.right, subtree.key, maxV)
    
    def getInorderSuccessor(self, key):
        subtree = self._root
        inorderSuccessor = None
        targetNode = self._bstSearch(subtree, key)
        if targetNode.right is not None:
            return self._bstMinimum(targetNode.right)
        else:
            ancestor = self._root
            while ancestor != targetNode:
                if ancestor.key > targetNode.key:
                    inorderSuccessor = ancestor
                    ancestor = ancestor.left
                else:
                    ancestor = ancestor.right
        return inorderSuccessor


bst = BinarySearchTree()
bst.add(7, 10)
bst.add(5, 12)
bst.add(1, 14)
bst.add(2, 16)
bst.add(9, 17)
bst.add(10, 13)
bst.add(8, 13)

for key in bst:
    print(key, bst.valueOf(key))

# print(bst.getTreeHeight())
# print(bst.isBinarySearchTree())
print(bst.getInorderSuccessor(8).key)

