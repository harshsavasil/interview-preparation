# Problem - Stock Span Problem
# Given a list of prices of stock on different days
# Find the number of consecutive smaller or equal elements for every element
# Time Complexity - O(n)
# video link - https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6

from collections import deque

# test case
elements = [100, 80, 60, 70, 60, 75, 85]
print("Initial array:")
print(elements)

# processing test case
stock_span = [1] * len(elements)
stack = deque()
for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] <= element:
            stack.pop()
        if len(stack) != 0:
            stock_span[index] = index - stack[-1][1]
        else:
            stock_span[index] += index
    stack.append((element, index))

print("stock span:")
print(stock_span)