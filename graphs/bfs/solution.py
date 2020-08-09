# Given a directed unweighted graph. perform dfs
from queue import Queue


def bfs(visited, node, directed_graph):
    bfs_queue = Queue()
    visited[node] = True
    bfs_queue.put(node)
    while not bfs_queue.empty():
        current_node = bfs_queue.get()
        print(current_node)
        for neighbor in directed_graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                bfs_queue.put(neighbor)


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
    visited = {node: False for node in directed_graph}
    for node in directed_graph:
        if not visited[node]:
            bfs(visited, node, directed_graph)
