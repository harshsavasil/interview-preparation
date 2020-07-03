# Problem Statement - Connect Ropes
# Given an array of length of ropes
# Find the minimum cost of connecting these ropes.
# cost of connecting two ropes of length X and Y = X + Y
# video link - https://www.youtube.com/watch?v=_k_c9nqzKN0&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=9
# solution - merge the ropes of minimum length at any time to get the minimum cost

import heapq

# test case
elements = [1, 2, 3, 4, 5]

# Processing test case
if len(elements) == 0:
    print(0)
min_heap = []
heapq.heapify(elements)
min_cost = 0
while len(elements) != 1:
    rope_x = heapq.heappop(elements)
    rope_y = heapq.heappop(elements)
    min_cost += (rope_x + rope_y)
    heapq.heappush(elements, rope_x + rope_y)
print("Min cost : {0}".format(min_cost))