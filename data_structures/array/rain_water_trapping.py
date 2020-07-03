# Problem - Rain water trapping
# Given a list of height of buildings
# Find the maximum water that can be trapped.
# video link - https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=9

from collections import deque

# processing test case
def maximum_water_trapped(heights):
    left_boundary = [None] * len(heights)
    right_boundary = [None] * len(heights)

    max_so_far = heights[0]
    for index, element in enumerate(heights):
        max_so_far = max(element, max_so_far)
        left_boundary[index] = max_so_far
    max_so_far = heights[-1]
    for index in range(len(heights) - 1, -1, -1):
        max_so_far = max(heights[index], max_so_far)
        right_boundary[index] = max_so_far
    
    max_water_trapped = 0
    for index, height in enumerate(heights):
        max_depth_for_each_building = min(left_boundary[index], right_boundary[index])
        max_water_trapped +=  (max_depth_for_each_building - height)
    
    return max_water_trapped

if  __name__ == '__main__':
    # elements = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2 , 1]
    elements = [3, 0, 0, 2, 0, 4]
    print("Height of Buildings:")
    print(elements)
    print("Maximum Water trapped: {0}".format(maximum_water_trapped(elements)))