# Problem - Max Area Histogram
# Given a list of height of bars in a histogram
# Find the maximum area covered by the bars of histogram
# video link - https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7

from collections import deque

# test case
elements = [6, 2, 5, 4, 5, 1, 6]
print("Initial array of heights of building:")
print(elements)

# processing test case
# Approach - for every building, go in both directions until a smaller building is found. Calculate the
# area and compare with the max_area and update if necessary.
# Step 1. Find Next Smaller Element for every element
# Step 2. Find Precious Smaller Element for every element
# Step 3. Calculate Area
# Step 4. Compare with max_area and update if necessary
previous_smaller_element_index = [-1] * len(elements)
next_smaller_element_index = [len(elements)] * len(elements)

stack = deque()
for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] >= element:
            stack.pop()
        if len(stack) != 0:
            previous_smaller_element_index[index] = stack[-1][1]
    stack.append((element, index))

while len(stack) != 0:
    stack.pop()

for index, element in enumerate(elements):
    if len(stack) != 0:
        while len(stack) != 0 and stack[-1][0] > element:
            top_of_stack = stack.pop()
            next_smaller_element_index[top_of_stack[1]] = index
    stack.append((element, index))

max_area = -1
for index in range(0, len(elements)):
    left_boundary = previous_smaller_element_index[index]
    right_boundary = next_smaller_element_index[index]
    area = (right_boundary - left_boundary - 1) * elements[index]
    max_area = max(area, max_area)

print("Maxium area covered by histogram: {0}".format(max_area))
