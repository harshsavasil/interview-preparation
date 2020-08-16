# TC - O (E * log(V))
from heapq import heappush, heappop
if __name__ == '__main__':
    directed_graph = {
        1: [(2, 1), (3, 5)],  # U:(V, weight)
        2: [(3, 6), (4, 10)],
        3: [(4, 4), (5, 1)],
        4: [(5, 12)],
        5: [],
        6: [(7, 1)],
        7: []
    }
    start_node = 1
    end_node = 3
    min_heap = []
    shortest_distance = {node: float('inf') for node in directed_graph}
    previous_node = {node: None for node in directed_graph}
    visited = {node: False for node in directed_graph}
    shortest_distance[start_node] = 0
    heappush(min_heap, (0, start_node))
    while len(min_heap) != 0:
        print('Heap : {0}'.format(min_heap))
        min_distance, current = heappop(min_heap)
        visited[current] = True
        if shortest_distance[current] < min_distance:  # added optimization 1
            continue
        # added optimization 3 - No need to look further as we have found the end node.
        if current == end_node:
            break
        for neighbor, distance in directed_graph[current]:
            if visited[neighbor]:  # added optimization 2
                continue
            new_distance = shortest_distance[current] + distance
            if new_distance < shortest_distance[neighbor]:
                previous_node[neighbor] = current
                shortest_distance[neighbor] = new_distance
                heappush(min_heap, (new_distance, neighbor))
    print(shortest_distance, previous_node)
