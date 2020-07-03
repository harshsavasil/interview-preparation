# Problem Statement - Sort a K sorted array
# Given a nearly sorted array or k sorted array
# A k-sorted array is an array in which for any index, the value for that index in sorted array is within the range of [index - k, index + k]
# We have to sort this nearly sorted array.
# video link - https://www.youtube.com/watch?v=dYfM6J1y0mU&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=4

import heapq

# test case
elements = [6, 5, 3, 2, 8, 10, 9]
k = 3

# Processing test case
print("Initial Array:")
print(elements)
min_heap = []
for index, element in enumerate(elements):
    heapq.heappush(min_heap, element)
    if len(min_heap) > k:
        min_value = heapq.heappop(min_heap)
        elements[index - k] = min_value

while min_heap:
    index += 1
    min_value = heapq.heappop(min_heap)
    elements[index - k] = min_value

print("Sorted Array:")
print(elements)
