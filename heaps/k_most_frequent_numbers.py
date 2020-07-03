# Problem Statement - Find Top K Frequent elements from an array
# Given an array of elements
# Find the k elements that have the highest frequency
# video link - https://www.youtube.com/watch?v=7VoJn544QrM&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=6

import heapq
from collections import defaultdict
# test case
elements = [1, 1, 3, 3, 1, 1, 2, 5, 3, 4, 5, 4, 6, 7]
k = 3
print("Initial Array:")
print(elements)

# Processing test case
frequency = defaultdict(int)

for element in elements:
    frequency[element] += 1

print("Frequency:")
print(frequency)

min_heap = []
for key in frequency:
    heapq.heappush(min_heap, (frequency[key], key))
    if len(min_heap) > k:
        heapq.heappop(min_heap)

print("Top {} Frequent Elements:".format(k))
print([x[1] for x in min_heap])