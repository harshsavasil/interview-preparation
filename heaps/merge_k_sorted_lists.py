from heapq import heappush, heappop
from typing import List

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        minHeap = []
        for index in range(len(lists)):
            if lists[index]:
                heappush(minHeap, (lists[index].val, index, lists[index]))
        newList = None
        prev = None
        while minHeap:
            _, row, node = heappop(minHeap)
            lists[row] = lists[row].next
            if lists[row]:  # insert if elements are left in the list
                heappush(minHeap, (lists[row].val, row, lists[row]))
            if newList is None:
                newList = node
            if prev:  # for head there is no previous
                prev.next = node
            prev = node
        return newList
