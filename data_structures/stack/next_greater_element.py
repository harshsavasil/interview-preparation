# Problem - Next Greater Element / Next Largest element
# Given a list of numbers
# Find the closest greater element for all elements on the right side, if no possible nge then set -1 as the result.
# Time Complexity - O(n)
# video link - https://www.youtube.com/watch?v=NXOOYYwpbg4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=2

from collections import deque

# test case
elements = [1, 3, 0, 0, 1, 2, 4]
print("Initial array:")
print(elements)

# processing test case
next_greater_element = [-1] * len(elements)
stack = deque()
for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] < element:
            top_of_stack = stack.pop()
            next_greater_element[top_of_stack[1]] = element
    stack.append((element, index))

print("Next Greater Element:")
print(next_greater_element)