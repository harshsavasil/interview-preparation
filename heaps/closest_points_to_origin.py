# Problem Statement
# Given a list of points (x, y).
# Find the k closest points to origin.
# Time Complexity - O(nlog(k))
# video link - https://www.youtube.com/watch?v=eaYX0Ee0Kcg&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev&index=5

import heapq
import math

class Point:
    def __init__ (self, x, y):
        self._x = x
        self._y = y

    def __lt__(self, other):
        return self.getDistanceFromOrigin() > other.getDistanceFromOrigin() # > for max heap
    
    def __eq__(self, other):
        return self.getDistanceFromOrigin() == other.getDistanceFromOrigin()
    
    def __gt__(self, other):
        return self.getDistanceFromOrigin() > other.getDistanceFromOrigin()

    def __str__(self):
        return "({0}, {1})".format(self._x, self._y)

    def getX(self):
        return self._x

    def getY(self):
        return self._y

    def getDistanceFromOrigin(self):
        return math.sqrt(self._x * self._x + self._y * self._y)

# input test case
points = [
    Point(-2, -4), Point(0, -2), Point(-1, 0),
    Point(-1, -4), Point(-1, -2), Point(1, 0),
    Point(2, -4), Point(-1, 2), Point(1, 2),
]
k = 3

# processing test case
closest_points = []
for point in points:
    heapq.heappush(closest_points, point)
    if len(closest_points) > k: # pop element if the length of heap crosses the limit
        heapq.heappop(closest_points)

heapq.heapify(points) # max Heap
print("Heap of size {0} is as follows : ".format(k))
for x in closest_points:
    print(x)
print("Heapified List is as follows : ")
for x in points:
    print(x)
print("{0} closest elements to origin are as follows : ".format(k))
for x in heapq.nlargest(k, points):
    print(x)