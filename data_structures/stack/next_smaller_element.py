# Problem - Next Smaller Element / Closest Smaller element to right
# Given a list of numbers
# Find the closest smaller element for all elements on the right side, if no possible nge then set -1 as the result.
# Time Complexity - O(n)
# video link - https://www.youtube.com/watch?v=T5s96ynzArg&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=5

from collections import deque

# test case
elements = [4, 1, 3, 0, 0, 1, 2, 4]
print("Initial array:")
print(elements)

# processing test case
next_smaller_element = [-1] * len(elements)
stack = deque()
for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] > element:
            top_of_stack = stack.pop()
            next_smaller_element[top_of_stack[1]] = element
    stack.append((element, index))

print("Next Smaller Element:")
print(next_smaller_element)