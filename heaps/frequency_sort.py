# Problem Statement - Frequency Sort
# Given an array of elements
# Sort elements on the basis of their frequency
# video link - https://www.youtube.com/watch?v=hLR5aMzYGGk&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=7

import heapq
from collections import defaultdict
# test case
elements = [1, 1, 3, 3, 1, 1, 2, 5, 5, 5, 3, 4, 5, 4, 6, 7]
print("Initial Array:")
print(elements)

# Processing test case
frequency = defaultdict(int)

for element in elements:
    frequency[element] += 1

print("Frequency:")
print(frequency)

max_heap = []
for key in frequency:
    heapq.heappush(max_heap, (-frequency[key], key))

ans = []
while max_heap:
    frequency, value = heapq.heappop(max_heap)    
    ans.extend([value] * -frequency)
print("Sorted Elements:")
print(ans)