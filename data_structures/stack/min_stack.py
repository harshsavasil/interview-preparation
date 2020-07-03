# Problem - Min Stack
# Given a list of numbers
# Implement a min stack
# video link - https://www.youtube.com/watch?v=asf9P2Rcopo&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=10

from collections import deque

class MinStack:
    """
    Min Stack using extra space
    Note: for constant space store (2 * element - minElement) in stack
    """
    def __init__(self, size):
        self._size = size
        self._count = 0
        self._primaryStack = deque()
        self._secondaryStack = deque()
    
    def push(self, element):
        assert self._count < self._size, "Stack overflow"
        self._primaryStack.append(element)
        if len(self._secondaryStack) == 0 or element <= self._secondaryStack[-1]:
            self._secondaryStack.append(element)
        self._count += 1

    def pop(self):
        assert self._count > 0, "Empty Stack."
        top_element = self._primaryStack.pop()
        if top_element == self._secondaryStack[-1]: # if top element of both stack matches pop the element.
            self._secondaryStack.pop()
        self._count -= 1
        return top_element
    
    def minElement(self):
        assert self._count > 0, "Empty Stack"
        return self._secondaryStack[-1]

min_stack = MinStack(5)
min_stack.push(18)
print(min_stack.minElement())
min_stack.push(19)
print(min_stack.minElement())
min_stack.push(29)
print(min_stack.minElement())
min_stack.push(15)
min_stack.push(15)
print(min_stack.minElement())
print(min_stack.pop())
print(min_stack.minElement())
min_stack.push(5)