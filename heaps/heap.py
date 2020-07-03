class MaxHeap:
    """
    An array-based implementation of the max-heap.
    """
    def __init__(self, maxSize):
        """
        Create a max-heap with maximum capacity of maxSize.
        """
        self._elements = [None] * maxSize
        self._count = 0
    
    def __len__(self):
        """
        Return the number of items in the heap.
        """
        return self._count
    
    def capacity(self):
        """
        Return the maximum capacity of the heap.
        """
        return len(self._elements)
    
    def top(self):
        """
        Return the top element of the heap.
        """
        return self._elements[0]
    
    def add(self, value):
        """
        Adds a new element to the heap
        @param: value
        """
        assert self._count < self.capacity(), "Cannot add to a full heap."
        self._elements[self._count] = value
        self._count += 1
        self._siftDown(self._count - 1)
    
    def extract(self):
        """
        Extract the maximum value from the heap.
        """
        assert self._count > 0, "Cannot extract from an empty heap."
        value = self._elements[0]
        self._count -= 1
        self._elements[0] = self._elements[ self._count ]
        # Sift the root value down the tree.
        self._siftDown(0)
        return value
    
    def _siftUp( self, index ):
        if index > 0:
            parent = index // 2
        if self._elements[index] > self._elements[parent] : # swap elements
            self._elements[index], self._elements[parent] = self._elements[parent], self._elements[index]
            self._siftUp(parent)
    
    def _siftDown( self, index ):
        left_child = 2 * index + 1
        right_child = 2 * index + 2
        # Determine which node contains the larger value.
        largest = index
        if left_child < self._count and self._elements[left_child] >= self._elements[largest] :
            largest = left_child
        elif right_child < self._count and self._elements[right_child] >= self._elements[largest]:
            largest = right_child
        # If the largest value is not in the current node (index), swap it with
        # the largest value and repeat the process.
        if largest != index :
            self._elements[index], self._elements[largest] = self._elements[largest], self._elements[index]
            self._siftDown(largest)