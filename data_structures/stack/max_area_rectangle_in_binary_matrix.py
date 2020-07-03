# Problem - Max Area Rectangle in Binary Matrix
# Given Binary Matrix
# Find the maximum area rectange
# video link - https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8

from collections import deque

# Approach
# Quite similar to MAH problem. Difference is of 2D vs 1D and whole numbers vs binary numbers.
# think of binary matrix as a set of buildings
# for every row, there will be a set of buildings
# use MAH to Calculate the max Area for a set of building
# and find the max for all such MAH

# processing test case
def max_area_histogram(heights):
    n = len(heights)
    previous_smaller_element_index = [-1] * n
    next_smaller_element_index = [n] * len(heights)

    stack = deque()
    for index, element in enumerate(heights):
        if len(stack) != 0:
            while len(stack) != 0 and stack[-1][0] >= element:
                stack.pop()
            if len(stack) != 0:
                previous_smaller_element_index[index] = stack[-1][1]
        stack.append((element, index))

    while len(stack) != 0:
        stack.pop()

    for index, element in enumerate(heights):
        if len(stack) != 0:
            while len(stack) != 0 and stack[-1][0] > element:
                top_of_stack = stack.pop()
                next_smaller_element_index[top_of_stack[1]] = index
        stack.append((element, index))

    max_area = -1
    for index in range(0, len(heights)):
        left_boundary = previous_smaller_element_index[index]
        right_boundary = next_smaller_element_index[index]
        area = (right_boundary - left_boundary - 1) * heights[index]
        max_area = max(area, max_area)

    return max_area

binary_matrix = [
    [0, 1, 1, 0],
    [1, 1, 1, 1],
    [1, 1, 1, 1],
    [1, 1, 0, 0]
]
max_area = -1
print("Binary Matrix:")
for row in range(0, len(binary_matrix)):
    if row != 0:
        for column in range(0, len(binary_matrix[row])):
            if binary_matrix[row][column] != 0:
                binary_matrix[row][column] += binary_matrix[row - 1][column]
    mah = max_area_histogram(binary_matrix[row])
    max_area = max(max_area, mah)

print("Max Area Rectange of Binary Matrix: {0}".format(max_area))