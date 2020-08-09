# Given a directed unweighted graph. perform dfs
from queue import Queue


def generate_previous_node_in_shortest_path(node, directed_graph):
    bfs_queue = Queue()
    visited = {node: False for node in directed_graph}
    prev = {node: None for node in directed_graph}
    visited[node] = True
    bfs_queue.put(node)
    while not bfs_queue.empty():
        current_node = bfs_queue.get()
        for neighbor in directed_graph[current_node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                prev[neighbor] = current_node
                bfs_queue.put(neighbor)
    return prev


def construct_shortest_path(start, end, prev):
    current = end
    path = []
    while current:
        path.append(current)
        current = prev[current]
    path.reverse()
    if path[0] == start:
        return path
    return []


def get_shortest_path(start, end, directed_graph):
    prev = generate_previous_node_in_shortest_path(start, directed_graph)
    return construct_shortest_path(start, end, prev)


if __name__ == '__main__':
    directed_graph = {
        1: [2],
        2: [3],
        3: [2, 4, 5],
        4: [5],
        5: [],
        6: [7],
        7: []
    }

    num_of_nodes = len(directed_graph)
    print(get_shortest_path(1, 5, directed_graph))
    print(get_shortest_path(1, 7, directed_graph))
