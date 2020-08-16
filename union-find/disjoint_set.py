class UnionFind:
    def __init__(self, size: int):
        assert type(
            size) is int and size >= 0, "Size must be a positive number."
        self._size = size
        self._numOfComponents = size
        self._componentSize = [1 for i in range(size)]
        self._parent = [i for i in range(size)]

    def find(self, node: int) -> int:
        """
        Performs path compression for all nodes in path to root and returns the root.
        """
        root = node
        while root != self._parent[root]:
            root = self._parent[root]
        # Compress the path leading to the root
        # Doing this operation is known as path compression.
        # and this is what gives us amortized time complexity.
        while node != root:
            nextNode = self._parent[node]
            self._parent[node] = root
            node = nextNode

        return root

    def connected(self, nodeA: int, nodeB: int) -> bool:
        """
        Returns True if nodeA and nodeB belong to same component else False.
        :param nodeA
        :param nodeB
        """
        return self.find(nodeA) == self.find(nodeB)

    def componentSize(self, p) -> int:
        """
        Returns the size of the component p belongs to.
        :param p
        """
        return self._size[self.find(p)]

    def size(self):
        """
        Returns the size of the disjoint set.
        """
        return self._size

    def components(self):
        """
        Returns the number of components in the disjoint set.
        """
        return self._numOfComponents

    def union(self, nodeA: int, nodeB: int):
        rootA = self.find(nodeA)
        rootB = self.find(nodeB)
        if rootA == rootB:
            return
        # Merge the smaller component into the larger one.
        if self._componentSize[rootA] < self._componentSize[rootB]:
            self._componentSize[rootB] += self._componentSize[rootA]
            self._parent[rootA] = rootB
        else:
            self._componentSize[rootA] += self._componentSize[rootB]
            self._parent[rootB] = rootA

        self._numOfComponents -= 1


if __name__ == "__main__":
    disjoint_set = UnionFind(size=10)
    disjoint_set.union(0, 1)
    disjoint_set.union(2, 4)
    disjoint_set.union(6, 5)
    disjoint_set.union(4, 5)
    disjoint_set.union(7, 8)
    disjoint_set.union(8, 9)
    print(disjoint_set.components)
