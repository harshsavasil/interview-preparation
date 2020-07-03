# Problem - Min Stack
# Given a list of numbers
# Implement a min stack using constant space
# video link - https://www.youtube.com/watch?v=asf9P2Rcopo&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=11

import sys
from collections import deque

class MinStack:
    """
    Min stack implementation using constant space
    Note: store (2 * element - minElement) in stack
    """
    def __init__(self, size):
        self._size = size
        self._count = 0
        self._primaryStack = deque()
        self._minElement = sys.maxsize
    
    def push(self, element):
        assert self._count < self._size, "Stack overflow"
        if len(self._primaryStack) == 0:
            self._minElement = element
            self._primaryStack.append(element)
        elif element >= self._minElement:
            self._primaryStack.append(element)
        else:
            self._minElement = element
            self._primaryStack.append(2 * element - self._minElement)
        self._count += 1

    def pop(self):
        assert self._count > 0, "Empty Stack."
        self._count -= 1
        top_element = self._primaryStack.pop()
        if top_element < self._minElement: # Anamoly case
            actual_element = 2 * self._minElement - top_element
            return actual_element
        return top_element
    
    def minElement(self):
        assert self._count > 0, "Empty Stack"
        return self._minElement
    
    def top(self):
        assert self._count > 0, "Empty Stack"
        top_element = self._primaryStack[-1]
        if top_element < self._minElement: # Anamoly case
            return self._minElement
        return top_element

min_stack = MinStack(5)
min_stack.push(18)
print(min_stack.minElement())
min_stack.push(19)
print(min_stack.minElement())
min_stack.push(29)
print(min_stack.top())
print(min_stack.minElement())
min_stack.push(15)
min_stack.push(15)
print(min_stack.minElement())
print(min_stack.pop())
print(min_stack.minElement())
print(min_stack.top())