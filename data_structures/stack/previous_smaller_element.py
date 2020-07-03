# Problem - Previous Smaller Element / Closest Smaller element to left
# Given a list of numbers
# Find the closest smaller element for all elements on the left side, if no possible nge then set -1 as the result.
# Time Complexity - O(n)
# video link - https://www.youtube.com/watch?v=T5s96ynzArg&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=4

from collections import deque

# test case
elements = [4, 1, 3, 0, 0, 1, 2, 4]
print("Initial array:")
print(elements)

# processing test case
previous_smaller_element = [-1] * len(elements)
stack = deque()
for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] >= element:
            stack.pop()
        if len(stack) != 0:
            previous_smaller_element[index] = stack[-1][0]
    stack.append((element, index))

print("Previous Smaller Element:")
print(previous_smaller_element)