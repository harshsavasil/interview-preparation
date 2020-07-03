class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class _LinkedListIterator:
    def __init__ (self, root):
        self.current = root

    def __iter__(self):
        return self

    def __next__(self):
        current = self.current
        if current is None:
            raise StopIteration
        self.current = self.current.next
        return current

class LinkedList:
    def __init__(self):
        self._head = None
        self._size = 0
    
    def __len__(self):
        return self._size

    def append(self, value):
        """
        Appends the value to the end of the list. TC - O(n)
        """
        node = Node(value)
        if self._head is None:
            self._head = node
        else:
            current = self._head
            while current.next:
                current = current.next
            current.next = node
        self._size += 1
    
    def insert(self, value, index=0):
        """
        Inserts the value to the start of the list if no index is passed. TC - O(n)
        """
        assert index < self._size, "Limit Execeeded."

        node = Node(value)
        if index == 0:
            node.next = self._head
            self._head = node
        else:
            count = 0
            current = self._head
            while count < index - 1 and current:
                current = current.next
                count += 1
            current.next = node
        self._size += 1
    
    def pop(self, index=0):
        """
        Removes the value from the start of the list if no index is passed. TC - O(n)
        """
        assert index < self._size, "Limit Execeeded."
        if index == 0:
            node.next = self._head
            self._head = node
        else:
            count = 0
            current = self._head
            while count < index - 1 and current:
                current = current.next
                count += 1
            current.next = node
        self._size += 1
    
    def __iter__(self):
        return _LinkedListIterator(self._head)

ll = LinkedList()
ll.append(1)
ll.insert(5)
ll.append("72a")
ll.insert(8, 4)

ll_iterator = iter(ll)
for element in ll_iterator:
    print(element.data)